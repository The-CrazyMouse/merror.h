#include "merror.h"
#include "msg.h"


int main() {

	// variables
	int total_tests = 0;
	int total_passed = 0;
	int total_failed = 0;

	errorP();
	// test 1 - check hasError
	if (hasError()) {
		total_tests++;
		total_failed++;
	} else {
		total_tests++;
		total_passed++;
	}

	// test 1 - set error
   	if (setError(101)) {
		total_tests++;
		total_passed++;
     } else {
		total_tests++;
		total_failed++;
	}

	errorP();

	printf("Total tests: %d\n", total_tests);
	printf("Total passed: %d\n", total_passed);
	printf("Total failed: %d\n", total_failed);
	
    return 0;
}

