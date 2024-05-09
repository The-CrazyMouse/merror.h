#include "merror.h"

void merror_set(Error err){
	error.error = err;
	
	

}
void msg_set(Error err){
	if (error.message != NULL) {
        free((void*)error.message);
    }
	if (err < 100){
		error.message = malloc(strlen(err_msg_gen[err][0])+1);
		strcpy((char*)error.message, err_msg_gen[err][0]);
	}

	
	// else if (error >= 100 && error < 200) {
	// 	err_msg_args[error-100];
	// }
	// else if (error >= 200 && error < 300) {
	// 	err_msg_dir[error-200];
	// }
	// else if (error >= 300 && error < 400) {
	// 	err_msg_file[error-300];
	// }
}

// void perror()
// void pnum_error();
// void pmsg_error();
