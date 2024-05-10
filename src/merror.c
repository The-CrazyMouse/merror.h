// Todo list:
// TODO: add a check for if the error was changed
// TODO: add a check for if the error was handled


#include "merror.h"


void merror(Error err){
	// set_error(&error, &err);
	
	error.error = (Error*)err;

	// i had to go with pointers so this doesn't seem to be needed
	// if (error.message != NULL) {
	// 	free((void*)error.message);
	// }
	// error.message = malloc(strlen(getMsg()+1));
	
	error.message = getMsg();
}

void errorP(){
	fprintf(stderr, "ERROR (%d): %s\n", *(error.error), error.message);
}

void errorPnum(){
	fprintf(stderr, "ERROR (%d)\n", *(error.error));
}

void errorPmsg(){
	fprintf(stderr, "ERROR: %s\n", error.message);
}
