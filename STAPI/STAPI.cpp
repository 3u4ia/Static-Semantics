#include "STAPI.h"
#include <string.h>
//vector<char *> varVec;	

/*
struct STAPIStruct {
	char *var
	int varUse = 0;
}

*/

void STAPI::insert(char *var) {
	varVec.push_back({var, 0});
	return;
}


bool STAPI::verify(char *var) {
	for (auto it = varVec.begin(); it != varVec.end(); ++it) {
		if(strcmp(var, it->var) == 0) {
			return true;
		}
	}
	return false;
}

void STAPI::checkVars(void) {
	for(auto it = varVec.begin(); it != varVec.end(); ++it) {
		if(it->varUse == 0) {
			printf("WARNING: identifier %s is unused\n", it->var);
		}
	}
	return;
}
