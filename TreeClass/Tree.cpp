#include "Tree.h"
//static void handleBlock(TreeNode *nodePtr);


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



void Tree::processNode(TreeNode *nodePtr) const {
	if(!nodePtr) {
		return;
	}

	switch(nodePtr->label) {
		case VARS:
			handleVars(nodePtr);
		default:
			break;
	}

	for(int i = 0; i < 3; i++) {
		processNode(nodePtr->nodeArr[i]);
	}
}

static handleVars(TreeNode *varNode) {
	if(varNode->tokenArr[0]) {
		
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



































