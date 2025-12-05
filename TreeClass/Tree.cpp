#include "Tree.h"
static void handleVars(TreeNode *, STAPI &);
static void handleVarList(TreeNode *, STAPI &);
static void handleVarUsage(TreeNode *, STAPI &);

void Tree::fileInitHelper(FILE **filePtr, const char *extension) {
	size_t newSize = strlen(baseFileName) + strlen(extension);
	char *fullFileName = (char *)malloc(newSize + 1);
	strcpy(fullFileName, baseFileName);
	strcat(fullFileName, extension);
	*filePtr = fopen(fullFileName, "w");
	if(!*filePtr) {
		perror("fopen failed");
	}
	free(fullFileName);
}



void Tree::displayPreOrder(TreeNode *nodePtr, size_t depth) const {
	if(nodePtr) {
		for(size_t i = 0; i < depth * 2; i++) fprintf(preOrderFile, " ");
		int tokenID = -1;
		fprintf(preOrderFile, "%s", nonTerminalNames[nodePtr->label]);
		for(size_t i = 0; i < 3; i++) {
			tokenID = nodePtr->tokenArr[i].tokenID;
			if (nodePtr->tokenArr[i].lineNum != -1) {
				fprintf(preOrderFile, " %s:%s:%d", tokenNames[tokenID - 1000], nodePtr->tokenArr[i].lexeme, nodePtr->tokenArr[i].lineNum);
			} else {
				break;
			}
		}
		fprintf(preOrderFile, "\n");
		for(int i = 0; i < 3; i++) {
			displayPreOrder(nodePtr->nodeArr[i], depth+1);
		}

	}
}


/*
vector<STAPIStruct> varVec;
	public:
		void insert(char *);
		bool verify(char *);
		void checkVars(void);
};

 */



void Tree::processNode(TreeNode *nodePtr) {
	if(!nodePtr) {
		return;
	}
	printf("current node being proc'd %s\n", nonTerminalNames[nodePtr->label]);

	switch(nodePtr->label) {
		case VARS:
			handleVars(nodePtr);
			break;
		case READ:
			handleVarUsage(nodePtr);
			break;
		case COND:
			handleVarUsage(nodePtr);
			break;
		case LOOP:
			handleVarUsage(nodePtr);
			break;
		case ASSIGN:
			handleVarUsage(nodePtr);
			break;
		case R:
			handleVarUsage(nodePtr);
			break;
		default:
			break;
	}

	for(int i = 0; i < 3; i++) {
		processNode(nodePtr->nodeArr[i]);
	}
}

void Tree::handleVarUsage(TreeNode *nodePtr) {
	if(!nodePtr){
		printf("handleCarUsage: nodePtr is null and it shouldn't be\n");
		exit(1);
	}
	if(nodePtr->tokenArr[0].lineNum == -1) {
		printf("handleVarUsage: nodePtr's first tk's linenum is -1 andi t shouldn't be\n");
		exit(1);
	}
	if(nodePtr->tokenArr[0].tokenID != IDTK) {
		printf("handleVarUsage: token isn't IDTK when it should be\n");
		exit(1);
	}
	apiObj.verify(nodePtr->tokenArr[0].lexeme);
}



void Tree::handleVars(TreeNode *varNode) {
	if(varNode->tokenArr[0].tokenID == IDTK) {
		apiObj.insert(varNode->tokenArr[0].lexeme);
	}
	TreeNode *varListNode = varNode->nodeArr[0];
	handleVarList(varListNode);	
}


void Tree::handleVarList(TreeNode *varListNode) {
	if(!varListNode) {
		return;
	}
	if(varListNode->tokenArr[0].lineNum == -1) {
		return;
	}
	else {
		apiObj.insert(varListNode->tokenArr[0].lexeme);
		handleVarList(varListNode->nodeArr[0]);
	}

}

/*
static void handleBlock(TreeNode *nodePtr) {
	int varCount = 0;
	TreeNode *varsNode = nodePtr->nodeArr[0];
	TreeNode *statsNode = nodePtr->nodeArr[1];

	handleVars(varsNode, varCount);
	processNode(statsNode); // process statements inside block

	for (int i = 0; i < varCount; i++) {
		//adapter.popID();
	}
	
	
}

static void handleVars(TreeNode *varNodePtr, int &varCount) {
	
	if(varNodePtr->tokenArr[0].lineNum == -1) { // if vars is an empty node
		return;
	}
	
	if(!varNodePtr->nodeArr[0]) { // if 
		return;
	} else if (varNodePtr->nodeArr[0].label == VARLIST) {
		handleVarList(varNodePtr->nodeArr[0]);
	}
}

*/



































