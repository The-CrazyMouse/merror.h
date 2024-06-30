#include "merror.h"
#include "msg.h"

static const bool trueVal = true;
static const bool falseVal = false;

static void set_error_copy(){
	err_copy.error = error.error;
	err_copy.message = error.message;
	err_copy.handled = error.handled;
}

bool merror(Error err){

	// NOTE: can't remember what this was for but was commented out so i'm just
	// gonna leave it like that for now because it doesn't seem to be needed
	// set_error(&error, &err);
	
		if(error.handled == &falseVal){
			fprintf(stderr, "DANGER: Error Not yet handled!\n");
			return false;
		}
	
	error.error = (Error*)err;

	// i had to go with pointers so this doesn't seem to be needed
	// if (error.message != NULL) {
	// 	free((void*)error.message);
	// }
	// error.message = malloc(strlen(getMsg()+1));
	
	error.message = getMsg();

	unhandled();

	set_error_copy();
	return true;
}


static void check_error_change(){
	if (error.error != NULL){
		if (error.error != err_copy.error){
			fprintf(stderr, "DANGER: Error changed was change!\n");
		}
		else if (error.message != err_copy.message){
			fprintf(stderr, "DANGER: Error message was change!\n");
		}
		else if (error.handled != err_copy.handled){
			fprintf(stderr, "DANGER: Error handled was change!\n");
		}
	}
}

void errorP(){
	check_error_change();
	fprintf(stderr, "ERROR (%d): %s\n", *(error.error), error.message);
}

void errorPnum(){
	check_error_change();
	fprintf(stderr, "ERROR (%d)\n", *(error.error));
}

void errorPmsg(){
	check_error_change();
	fprintf(stderr, "ERROR: %s\n", error.message);
}

void handled(){
	check_error_change();
	error.handled = &trueVal;
	err_copy.handled = &trueVal;
}

void unhandled(){
	check_error_change();
	error.handled = &falseVal;
	err_copy.handled = &falseVal;
}

void clearError(){
	check_error_change();
	error.error = NULL;
	error.message = NULL;
	error.handled = &falseVal;

	set_error_copy();
}


