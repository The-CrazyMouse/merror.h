#include <stdio.h>
#include <stdlib.h>
#include "tests.h"



bool testResult_enum(Error err){
	if(error.error == err){
		return true;
	}
	else{
		return false;
	}
}
bool testResult_message(char msgi[]){
	if (strcmp(error.message, msg) == 0){ 
		return true;
	}
	else{
		return false;
	}
}

bool testResult_getMsg(char msg[]){
	if (strcmp(getMsg(), msg) == 0){
		return true;
	}
	else{
		return false;
	}
}

bool testresult_merrorP();
bool testresult_merrorPnum();
bool testresult_merrorPmsg();

bool test_tryChange();
