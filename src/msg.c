// Todo List:
// TODO: add a check to see if the message actually exists



#include "msg.h"
#include "merror.h"

static const char* err_msg_gen[100][20]= {
	{"No error"},
	{"Unknown Error"},
	{"Message Not Found"},
};

static const char* err_msg_args[100][20] = {
	{"No Arguments"},
	{"Invalid Command"},
	{"Too Few Arguments"},
	{"Too Many Arguments"},
	{"Null Argument"},
	{"Invalid Flag"},
	{"Invalid Arguments"},
	{"Invalid Argument Type"},
	{"Invalid Argument Value"},
	{"Invalid Argument Format"},
};

static const char* err_msg_dir[100][20] = {
	{"Directory Is Not Found"},
	{"Directory Is Not Empty"},
};

static const char* err_msg_file[100][20] = {
	{"File Not Found"},
	{"File Not Open"},
	{"File Not Closed"},
	{"File Already Exists"},
};



const char* getMsg(){

// WARNING: this function does not check if the message actually exists

	Error err = *(error.error);

	if (err < 100){
		return err_msg_gen[err][0];
	}
	else if (err >= 100 && err < 200) {
		return err_msg_args[err - 100][0];
	}
	else if (err >= 200 && err < 300) {
		return err_msg_dir[err - 200][0];
	}
	else if (err >= 300 && err < 400) {
		return err_msg_file[err - 300][0];
	}
	else{
		return err_msg_gen[2][0];
	}
	return err_msg_gen[2][0];
}
