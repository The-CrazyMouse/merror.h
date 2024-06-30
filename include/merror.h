#ifndef MERROR_H
#define MERROR_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum {

	//general errors
	// 000 - 099
	NO_ERROR = 000,
	UNKNOWN_ERROR = 001,
	MESSAGE_NOT_FOUND = 002,

	//argument errors
	// 100 - 199
	NO_ARGUMENTS = 100,
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
	const Error* error;
	const char* message;
	const bool* handled;
} Merror;

extern Merror error;
extern Merror err_copy;

// so aparanetly you don't need and can't have a static function declared in a header file
// static void set_error_copy();

bool merror(Error error);
void handled();
void unhandled();
void clearError();
void errorP();
void errorPnum();
void errorPmsg();

#endif // !MERROR_H
