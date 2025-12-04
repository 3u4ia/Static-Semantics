#ifndef TREE_H
#define TREE_H
#include "TreeNodeStruct.h"
#include "../TokensAndStates/TokensAndStates.h"
#include "../STAPI/STAPI.h"
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>

class Tree {
	private:
		TreeNode *root;
		STAPI apiObj;
		char *baseFileName;
		FILE *inOrderFile = NULL;
		FILE *preOrderFile = NULL;
		FILE *postOrderFile = NULL;
		void displayPreOrder(TreeNode *, size_t) const;
		int smallChange = 0;
		void fileInitHelper(FILE **, const char *);
		void processNode(TreeNode *) const;
		
	public:
		Tree(char *fileName) {
			root = nullptr;
			if(fileName == nullptr){
				baseFileName = "out";
			} else {
				baseFileName = fileName; // Allocating new memory and copying the contents of the str
			}
			
			fileInitHelper(&preOrderFile, ".preorder");
		}
		Tree(char *fileName, TreeNode *root) {
			this->root = root;
			if(fileName == nullptr) {
				baseFileName = "out";
			} else {
				baseFileName = fileName;
			}

			fileInitHelper(&preOrderFile, ".preorder");
		}
		~Tree() {
			if(inOrderFile) {
				fclose(inOrderFile);
			}
			if(preOrderFile) {
				fclose(preOrderFile);
			}
			if(postOrderFile) {
				fclose(postOrderFile);
			}

		}

		void displayPreOrder()const {
			displayPreOrder(root, 0);
		}

		void processNode()const {
			processNode(root);
		}

		
};


#endif

