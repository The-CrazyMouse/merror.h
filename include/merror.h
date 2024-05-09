#ifndef MERROR_H
#define MERROR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "msg.h"


typedef enum {

	//general errors
	// 000 - 099
	NO_ERROR = 000,
	UNKNOWN_ERROR = 001,

	//argument errors
	// 100 - 199
	NO_ARGUMENT = 100,
	INVALID_COMMAND = 101,
	TOO_FEW_ARGUMENTS = 102,
	TOO_MANY_ARGUMENTS = 103,
	NULL_ARGUMENT = 104,
	INVALID_FLAG = 105,
	INVALID_ARGUMENT = 106,
	INVALID_ARGUMENT_TYPE = 107,
	INVALID_ARGUMENT_VALUE = 108,
	INVALID_ARGUMENT_FORMAT = 109,

	//directory errors
	// 200 - 299
	DIRECTORY_NOT_FOUND= 200,
	DIRECTORY_NOT_EMPTY = 201,
	
	
	//file errors
	// 300 - 399
	FILE_NOT_FOUND= 300,
	FILE_NOT_OPEN = 301,
	FILE_NOT_CLOSED = 302,
	FILE_ALREADY_EXISTS = 303,

} Error;


typedef struct {
	Error error;
	const char* message;
} Merror;

extern Merror error;

void merror_set(Error error);
// void get_msg(Error error);
// // void perror();
// void pnum_error();
// void pmsg_error();

#endif // !MERROR_H
