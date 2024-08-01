# Documentation

## Introduction
  This is a simple error handling library for C. Nothing fancy, just prints a code
or/and a message to stderr.
  To make it a bit safer the library only exposes the functions not the actual error.
  The error has also a copy to be compared with to avoid changing the error in a
not intended way.



## Usage 

### Add the library to your project
  Just add the static or dynmaic library to your project and include the merror.h header file.
  After that just include the header file in your source file and you are ready to go.

  ```c
  #include "merror.h"
  ```

### Set an error
  To set an error just call the function `setError` with the error code.
  the error code is and enum so you can either use the enum or the number.

  ```c
  setError(301);
  setError(FILE_NOT_OPEN);
  ```
  Note: The enum may make it easier to read the code.
  Note: The function returns a bool to indicate if the error was set or not. Just in case you want to check.


### Print the error
  To print the error just call the function `errorP`, `errorPnum` or `errorPmsg`.
  The `errorP` function will print the error code and the message.
  The `errorPnum` function will print only the error code.
  The `errorPmsg` function will print only the message.

  ```c
  errorP();
  errorPnum();
  errorPmsg();
  ```


### Handle the error
  When you get and error and have handled it you can set it as handled.
  To handle the error just call the function `handle`.
  This will set the handled flag to true.
  This however will not clear the error. But it will allow for it to be rewritten with a new error.
  You can reverse this by calling the function `unhandle`.
  If you wish to clear the error you can call the function `clearError`.
  This will rewrite the error with the default error.

  ```c
  handle();
  unhandle();
  clearError();
  ```

  Note: A handled error before being cleared or rewritten can still be accessed and printed.


### Check the error
  While you don't have direct access to the error you can still check the diferent parts of the error.
  To check if there is an error you can call the function `hasError`.
  To get the error code you can call the function `getCode`.
  To get the error message you can call the function `getMsg`.
  To get the handled flag you can call the function `getHandled`.

  ```c
  hasError();
  getCode();
  getMsg();
  getHandled();
  ```

  Note: the functions `hasError` and `getHandled` may seem the same but they are slightly different. 
        `hasError` will return true if there is an unhadled error and false if there is not.
        `getHandled` will return true if the the actual valeu of the handled flag is true and false if it is false.


### Error codes

  I will leave here the codes, enum and messages for the errors.
  I will try to add more as I go.
  For now they are seperated by 100s for the different types of errors.
  0 to 100 are general errors.
  100 to 200 are for command line arguments related errors.
  200 to 300 are for directory related errors. 
  300 to 400 are for file related errors. 

  Warning: This may change in the future, so don't get too attached to it.
 

  ```c
| Code | Enum                     | Message                      |
|------|--------------------------|------------------------------|
| 000  | NO_ERROR                 | No error                     |
| 001  | UNKNOWN_ERROR            | Unknown Error                |
| 002  | MESSAGE_NOT_FOUND        | Message Not Found            |
| 100  | NO_ARGUMENTS             | No Arguments                 |
| 101  | INVALID_COMMAND          | Invalid Command              |
| 102  | TOO_FEW_ARGUMENTS        | Too Few Arguments            |
| 103  | TOO_MANY_ARGUMENTS       | Too Many Arguments           |
| 104  | NULL_ARGUMENT            | Null Argument                |
| 105  | INVALID_FLAG             | Invalid Flag                 |
| 106  | INVALID_ARGUMENT         | Invalid Arguments            |
| 107  | INVALID_ARGUMENT_TYPE    | Invalid Argument Type        |
| 108  | INVALID_ARGUMENT_VALUE   | Invalid Argument Value       |
| 109  | INVALID_ARGUMENT_FORMAT  | Invalid Argument Format      |
| 200  | DIRECTORY_NOT_FOUND      | Directory Was Not Found      |
| 201  | DIRECTORY_NOT_EMPTY      | Directory Is Not Empty       |
| 202  | DIRECTORY_FAIL_CREATE    | Directory Failed To Create   |
| 300  | FILE_NOT_FOUND           | File Not Found               |
| 301  | FILE_NOT_OPEN            | File Not Open                |
| 302  | FILE_NOT_CLOSED          | File Not Closed              |
| 303  | FILE_ALREADY_EXISTS      | File Already Exists          |

