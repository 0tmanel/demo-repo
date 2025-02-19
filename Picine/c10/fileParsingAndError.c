//The dirname() and basename() functions break a pathname string into directory and filename parts. (These functions perform a similar task to the dirname(1) and basename(1) commands.)
#include <libgen.h>
char *dirname(char *pathname);
char *basename(char *pathname);
//Both return a pointer to a null-terminated (and possibly statically allocated) string

//For example, given the pathname /home/britta/prog.c, dirname() returns /home/britta and basename() returns prog.c. Concatenating the string returned by dirname(), a slash (/), and the string returned by basename() yields a complete pathname.
//Note the following points regarding the operation of dirname() and basename():
//  Trailing slash characters in pathname are ignored.
//  If pathname doesn’t contain a slash, then dirname() returns the string . (dot) and basename() returns pathname.
//  If pathname consists of just a slash, then both dirname() and basename() return the string /. Applying the concatenation rule above to create a pathname from these returned strings would yield the string ///. This is a valid pathname. Because multiple consecutive slashes are equivalent to a single slash, the path- name /// is equivalent to the pathname /.


//###################################################

//ERROR HANDLING /  STRERROR

//When an error occurs in one of the UNIX System functions, a negative value is often returned, and the integer errno is usually set to a value that tells why. For example, the open function returns either a non-negative file descriptor if all is OK or −1 if an error occurs. An error from open has about 15 possible errno values, such as file doesn’t exist, permission problem, and so on.

//The strerror() function returns the error string corresponding to the error number given in its errnum argument.
#include <string.h>
char *strerror(int errnum);
// Returns pointer to error string corresponding to errnum
//The string returned by strerror() may be statically allocated, which means that it could be overwritten by subsequent calls to strerror().
//If errnum specifies an unrecognized error number, strerror() returns a string of the form Unknown error nnn. On some other implementations, strerror() instead returns NULL in this case.
/*
Preprocessor define   Description
EFAULT              Bad address
EFBIG               File too large
EINTR               System call was interrupted
EINVAL              Invalid argument
EIO                 I/O error
EISDIR              Is a directory
EMFILE              Too many open files
EMLINK              Too many links
ENFILE              File table overflow
ENODEV              No such device
ENOENT              No such file or directory
ENOEXEC             Exec format error
ENOMEM              Out of memory
ENOSPC              No space left on device
ENOTDIR             Not a directory
ENOTTY              Inappropriate I/O control operation 
ENXIO               No such device or address 
EPERM               Operation not permitted
EPIPE               Broken pipe
ERANGE              Result too large
EROFS               Read-only filesystem
ESPIPE              Invalid seek
ESRCH               No such process
ETXTBSY             Text file busy
EXDEV               Improper link
*/

//unctions notify the caller of errors via a special return value, which is usually −1 (the exact value used depends on the function). The error value alerts the caller to the oc‐ currence of an error but provides no insight into why the error occurred. The errno variable is used to find the cause of the error.
//This variable is declared in <errno.h> as follows: extern int errno;
// The errno variable may be read or written directly; it is a modifiable lvalue. The value of errno maps to the textual description of a specific error. A preprocessor #define also maps to the numeric errno value. For example, the preprocessor define EACCES equals 1, and represents “permission denied.” 

//##!!!errno is automatically set by system calls, you should never manually assign it.
//##!!!!!!when open() fails, errno already holds the error code. You do not need to set it yourself.

