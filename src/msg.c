#include "msg.h"
#include "merror.h"

static const char* err_msg_gen[100]= {
	"No error",
	"Unknown Error",
	"Message Not Found",
};

static const char* err_msg_args[100]= {
	"No Arguments",
	"Invalid Command",
	"Too Few Arguments",
	"Too Many Arguments",
	"Null Argument",
	"Invalid Flag",
	"Invalid Arguments",
	"Invalid Argument Type",
	"Invalid Argument Value",
	"Invalid Argument Format",
};

static const char* err_msg_dir[100]= {
	"Directory Was Not Found",
	"Directory Is Not Empty",
	"Directory Failed To Create",
};

static const char* err_msg_file[100]= {
	"File Not Found",
	"File Not Open",
	"File Not Closed",
	"File Already Exists",
};



char* findMsg(Error err){

	const char* msg;

	if (err < 100){
		msg = err_msg_gen[err];
		// return err_msg_gen[err][0];
	}
	else if (err >= 100 && err < 200) {
		msg = err_msg_args[err - 100];
		// return err_msg_args[err - 100][0];
	}
	else if (err >= 200 && err < 300) {
		msg = err_msg_dir[err - 200];
		// return err_msg_dir[err - 200][0];
	}
	else if (err >= 300 && err < 400) {
		msg = err_msg_file[err - 300];
		// return err_msg_file[err - 300][0];
	}
	else{
		msg = err_msg_gen[2];
		// return err_msg_gen[2][0];
	}
	if (msg == NULL){
		return (char*)err_msg_gen[2];
	}
	else{
		return (char*)msg;
	}
}
