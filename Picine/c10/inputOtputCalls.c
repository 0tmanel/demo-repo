//   OPEN

// The open() system call either opens an existing file or creates and opens a new file.
#include <sys/stat.h>
#include <fcntl.h>
int open(const char *pathname, int flags, ... /* mode_t mode */);

//The open() system call maps the file given by the pathname name to a file descriptor, which it returns on success. The file position is to the start of the file (zero) and the file is opened for access according to the flags given by flags.

// The file to be opened is identified by the pathname argument. If pathname is a symbolic link, it is dereferenced. On success, open() returns a file descriptor that is used to refer to the file in subsequent system calls. If an error occurs, open() returns –1 and errno is set accordingly.

// The flags argument is a bit mask that specifies the access mode for the file, using one of the constants

// When open() is used to create a new file, the mode bit-mask argument specifies the permissions to be placed on the file. (The mode_t data type used to type mode is an integer type specified in SUSv3.) If the open() call doesn’t specify O_CREAT, mode can be omitted.

// Access mode  Description
// O_RDONLY  Open the file for reading only
// O_WRONLY  Open the file for writing only
//  O_RDWR  Open the file for both reading and writing

//######################################################

// READ

//read() function is used to read data from a file descriptor into a buffer
// The read() system call reads data from the open file referred to by the descriptor fd.
#include <unistd.h>
ssize_t read(int fd, void *buffer, size_t count);
// Returns number of bytes read, 0 on EOF, or –1 on error
// The count argument specifies the maximum number of bytes to read. (The size_t data type is an unsigned integer type.) The buffer argument supplies the address of the memory buffer into which the input data is to be placed. This buffer must be at least count bytes long.
// When read() is applied to other types of files—such as pipes, FIFOs, sockets, or terminals—there are also various circumstances where it may read fewer bytes than requested. For example, by default, a read() from a terminal reads characters only up to the next newline (\n) character.
#define MAX_READ 20
int main()
{

    char buffer[MAX_READ];
    if (read(STDIN_FILENO, buffer, MAX_READ) == -1)
        errExit("read");
    printf("The input data was: %s\n", buffer);
}
// The output from this piece of code is likely to be strange, since it will probably include characters in addition to the string actually entered. This is because read() doesn’t place a terminating null byte at the end of the string that printf() is being asked to print. A moment’s reflection leads us to realize that this must be so, since read() can be used to read any sequence of bytes from a file.  so remember :

// read() reads up to a specified number of bytes from a file descriptor and stores them in a buffer.

// The read() function returns the number of bytes actually read, and it doesn't add a null terminator ('\0') to the data in the buffer.
//If a terminating null byte is required at the end of the input buffer, we must put it there explicitly:
int main()
{

    char buffer[MAX_READ + 1];
    ssize_t numRead;
    numRead = read(STDIN_FILENO, buffer, MAX_READ);
    if (numRead == -1)
        errExit("read");
    buffer[numRead] = '\0';
    printf("The input data was: %s\n", buffer);
}

//######################################################

// WRITE

//The write() system call writes data to an open file.
#include <unistd.h>
ssize_t write(int fd, void *buffer, size_t count);
//Returns number of bytes written, or –1 on er

//The arguments to write() are similar to those for read(): buffer is the address of the data to be written; count is the number of bytes to write from buffer; and fd is a file descriptor referring to the file to which data is to be written.
//On success, write() returns the number of bytes actually written; this may be less than count. For a disk file, possible reasons for such a partial write are that the disk was filled or that the process resource limit on file sizes was reached. 
//When performing I/O on a disk file, a successful return from write() doesn’t guarantee that the data has been transferred to disk, because the kernel performs buffering of disk I/O in order to reduce disk activity and expedite write() calls. We consider the details in 

//#####################################################

// CLOSE

//The close() system call closes an open file descriptor, freeing it for subsequent reuse by the process. When a process terminates, all of its open file descriptors are auto- matically closed.
#include <unistd.h> 
int close(int fd);
//It is usually good practice to close unneeded file descriptors explicitly, since this makes our code more readable and reliable in the face of subsequent modifica- tions. Furthermore, file descriptors are a consumable resource, so failure to close a file descriptor could result in a process running out of descriptors. This is a partic- ularly important issue when writing long-lived programs that deal with multiple files, such as shells or network servers.
//Just like every other system call, a call to close() should be bracketed with error- checking code, such as the following:
               //if (close(fd) == -1)
                   //errExit("close");
//This catches errors such as attempting to close an unopened file descriptor or close the same file descriptor twice, and catches error conditions that a specific file sys- tem may diagnose during a close operation.
//NFS (Network File System) provides an example of an error that is specific to a file system. If an NFS commit failure occurs, meaning that the data did not reach the remote disk, then this error is propagated to the application as a fail- ure in the close() cal