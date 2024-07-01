#include "merror.h"
#include "msg.h"

static Merror error = {0, NULL, true};
static Merror err_copy = {0, NULL, true};

static void set_error_copy() {
	err_copy.error = error.error;
	err_copy.message = error.message;
	err_copy.handled = error.handled;
}

bool hasError(){
	if(error.error == 0){
		return false;
	} else{
		if(error.handled == true){
			return false;
		}
		else {
			if(error.handled == false){
				return true;
			} else{
				return false;
			}
		}
	}
	return true;
}

static bool check_error_change(){
	if (error.error != 0){
		if (error.error != err_copy.error){
			fprintf(stderr, "DANGER: Error changed was change!\n");
			return true;
		}
		if (error.message != err_copy.message){
			fprintf(stderr, "DANGER: Error message was change!\n");
			return true;
		}
		if (error.handled != err_copy.handled){
			fprintf(stderr, "DANGER: Error handled was change!\n");
			return true;
		}
	}
	return false;
}

bool setError(Error err){
	if(error.error != 0){
		if(check_error_change()){
			return false;
		}else if(hasError()){
			fprintf(stderr, "DANGER: Error Not yet handled!\n");
			return false;
		}
	} else {
		error.error = err;
		error.message = findMsg(err);
		if(err == 0){
			error.handled = true;
		} else {
			error.handled = false;
		}
		set_error_copy();
		return true;
	}
	return false;
}

void errorP(){
	check_error_change();
	fprintf(stderr, "ERROR (%d): %s\n", error.error, error.message);
}

void errorPnum(){
	check_error_change();
	fprintf(stderr, "ERROR (%d)\n", error.error);
}

void errorPmsg(){
	check_error_change();
	fprintf(stderr, "ERROR: %s\n", error.message);
}

void handle(){
	check_error_change();
	if (error.error == 0){
		return;
	} else{
		if (hasError()) {
			error.handled = true;
			err_copy.handled = true;
		}
	}
}

void unhandle(){
	check_error_change();
	if(error.error == 0){
		return;
	} else {
		if (!hasError()) {
			error.handled = false;
			err_copy.handled = false;
		}
	}
}

void clearError(){
	check_error_change();
	error.error = 0;
	error.message = NULL;
	error.handled = true;
	set_error_copy();
}

int getCode(){
	return error.error;
}

char* getMsg(){
	return error.message;
}

bool getHandle(){
	return error.handled;
}
