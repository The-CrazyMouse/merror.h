#include <stdio.h>
#include "tests.h"

extern Merror error;

void testPassed(int *total, int *passed){
	(*total)++;
	(*passed)++;
}
void testFailed(int *total, int *failed){
	(*total)++;
	(*failed)++;
}


int main(int argc, char *argv[])
{

	int total = 0;
	int passed = 0;
	int failed = 0;

	printf("Testing enum.c\n");
	printf("***************************************************\n");
	printf("\n");

	/***********************************************************
	 *				 Testing General Errors
	 **********************************************************/
	printf("Testing General Errors\n");
	printf("***************************************************\n");
	printf("\n");

	// NO ERROR
	printf("Testing error: NO ERROR\n");
	printf("Testing code: ");
	setError(NO_ERROR);
	if (testResult_enum(NO_ERROR) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");
	
	// UNKNOWN ERROR
	printf("Testing error: UNKNOWN ERROR\n");
	printf("Testing code: ");
	error.error = UNKNOWN_ERROR;
	if (testResult_enum(UNKNOWN_ERROR) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");
	
	// MESSAGE NOT FOUND
	printf("Testing error: MESSAGE_NOT_FOUND\n");
	printf("Testing code: ");
	error.error = MESSAGE_NOT_FOUND;
	if (testResult_enum(MESSAGE_NOT_FOUND) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");
	

	/***********************************************************
	 *				 Testing Arguments Errors
	 **********************************************************/
	printf("Testing Arguments Errors\n");
	printf("***************************************************\n");
	printf("\n");

	// NO ARGUMENTS
	printf("Testing error: NO ARGUMENTS\n");
	printf("Testing code: ");
	setError(NO_ARGUMENTS);
	if (testResult_enum(NO_ARGUMENTS) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");
	
	// INVALID COMMAND
	printf("Testing error: INVALID COMMAND\n");
	printf("Testing code: ");
	error.error = INVALID_COMMAND;
	if (testResult_enum(INVALID_COMMAND) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");
	
	// TOO FEW ARGUMENTS
	printf("Testing error: TOO FEW ARGUMENTS\n");
	printf("Testing code: ");
	error.error = TOO_FEW_ARGUMENTS;
	if (testResult_enum(TOO_FEW_ARGUMENTS) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");

	// 
	printf("Testing error: TOO MANY ARGUMENTS\n");
	printf("Testing code: ");
	setError(TOO_MANY_ARGUMENTS);
	if (testResult_enum(TOO_MANY_ARGUMENTS) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");
	
	// NULL ARGUMENT
	printf("Testing error: NULL ARGUMENT\n");
	printf("Testing code: ");
	error.error = NULL_ARGUMENT;
	if (testResult_enum(NULL_ARGUMENT) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");

	// INVALID FLAG
	printf("Testing error: INVALID FLAG\n");
	printf("Testing code: ");
	error.error = INVALID_FLAG;
	if (testResult_enum(INVALID_FLAG) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");

	// INVALID ARGUMENT
	printf("Testing error: INVALID ARGUMENT\n");
	printf("Testing code: ");
	setError(INVALID_ARGUMENT);
	if (testResult_enum(INVALID_ARGUMENT) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");
	
	// INVALID ARGUMENT TYPE
	printf("Testing error: INVALID_ARGUMENT_TYPE\n");
	printf("Testing code: ");
	setError(INVALID_ARGUMENT_TYPE);
	if (testResult_enum(INVALID_ARGUMENT_TYPE) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");
	
	// INVALID ARGUMENT VALUE
	printf("Testing error: INVALID ARGUMENT VALUE\n");
	printf("Testing code: ");
	setError(INVALID_ARGUMENT_VALUE);
	if (testResult_enum(INVALID_ARGUMENT_VALUE) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");

	// INVALID ARGUMENT FORMAT
	printf("Testing error: INVALID ARGUMENT FORMAT\n");
	printf("Testing code: ");
	setError(INVALID_ARGUMENT_FORMAT);
	if (testResult_enum(INVALID_ARGUMENT_FORMAT) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");
	

	/***********************************************************
	 *				 Testing Directory Errors
	 **********************************************************/
	printf("Testing Directory Errors\n");
	printf("***************************************************\n");
	printf("\n");

	// NO ARGUMENTS
	printf("Testing error: DIRECTORY_NOT_FOUND\n");
	printf("Testing code: ");
	setError(DIRECTORY_NOT_FOUND);
	if (testResult_enum(DIRECTORY_NOT_FOUND) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");
	
	// DIRECTORY_NOT_EMPTY
	printf("Testing error: DIRECTORY_NOT_EMPTY\n");
	printf("Testing code: ");
	error.error = DIRECTORY_NOT_EMPTY;
	if (testResult_enum(DIRECTORY_NOT_EMPTY) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");

	/***********************************************************
	 *				 Testing File Errors
	 **********************************************************/
	printf("Testing File Errors\n");
	printf("***************************************************\n");
	printf("\n");

	// FILE_NOT_FOUND
	printf("Testing error: FILE_NOT_FOUND\n");
	printf("Testing code: ");
	setError(FILE_NOT_FOUND);
	if (testResult_enum(FILE_NOT_FOUND) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");
	
	// FILE_NOT_OPEN
	printf("Testing error: FILE_NOT_OPEN\n");
	printf("Testing code: ");
	error.error = FILE_NOT_OPEN;
	if (testResult_enum(FILE_NOT_OPEN) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");
	
	//FILE_NOT_CLOSED
	printf("Testing error: FILE_NOT_CLOSED\n");
	printf("Testing code: ");
	error.error = FILE_NOT_CLOSED;
	if (testResult_enum(FILE_NOT_CLOSED) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");

	// FILE_ALREADY_EXISTS
	printf("Testing error: FILE_ALREADY_EXISTS\n");
	printf("Testing code: ");
	error.error = FILE_ALREADY_EXISTS;
	if (testResult_enum(FILE_ALREADY_EXISTS) == true){
		printf("Passed\n");
		testPassed(&total, &passed);
	}
	else{
		printf("Failed\n");
		testFailed(&total, &failed);
	}
	printf("\n");

	return EXIT_SUCCESS;
}
