#ifndef TESTS_H
#define TESTS_H

#include "message.h"
#include "merror.h"

bool testResult_message(char msg[]);
bool testResult_enum(Error err);
bool testResult_getMsg(char msg[]);
bool testresult_merrorP();
bool testresult_merrorPnum();
bool testresult_merrorPmsg();

bool test_tryChange();

#endif // !TESTS_H
