//   OPEN

// The open() system call either opens an existing file or creates and opens a new file.
#include <sys/stat.h>
#include <fcntl.h>
int open(const char *pathname, int flags, ... /* mode_t mode */);

//The open() system call maps the file given by the pathname name to a file descriptor, which it returns on success. The file position is to the start of the file (zero) and the file is opened for access according to the flags given by flags.

// The file to be opened is identified by the pathname argument. If pathname is a symbolic link, it is dereferenced. On success, open() returns a file descriptor that is used to refer to the file in subsequent system calls. If an error occurs, open() returns –1 and errno is set accordingly.

// The flags argument is a bit mask that specifies the access mode for the file, using one of the constants

// When open() is used to create a new file, the mode bit-mask argument specifies the permissions to be placed on the file. (The mode_t data type used to type mode is an integer type specified in SUSv3.) If the open() call doesn’t specify O_CREAT, mode can be omitted.

// 1 : O_RDONLY
// Open for reading only.
// 2 : O_WRONLY
// Open for writing only.
// 3 : O_RDWR
// Open for reading and writing. The result is undefined if this flag is applied to a FIFO.
// Any combination of the following may be used:

// 4 : O_APPEND
// If set, the file offset shall be set to the end of the file prior to each write.
// 5 : O_CREAT
// If the file exists, this flag has no effect except as noted under O_EXCL below. Otherwise, the file shall be created; the user ID of the file shall be set to the effective user ID of the process; the group ID of the file shall be set to the group ID of the file's parent directory or to the effective group ID of the process; and the access permission bits (see <sys/stat.h>) of the file mode shall be set to the value of the third argument taken as type mode_t modified as follows: a bitwise AND is performed on the file-mode bits and the corresponding bits in the complement of the process' file mode creation mask. Thus, all bits in the file mode whose corresponding bit in the file mode creation mask is set are cleared. When bits other than the file permission bits are set, the effect is unspecified. The third argument does not affect whether the file is open for reading, writing, or for both. Implementations shall provide a way to initialize the file's group ID to the group ID of the parent directory. Implementations may, but need not, provide an implementation-defined way to initialize the file's group ID to the effective group ID of the calling process.
// 6 : O_DSYNC
// [SIO] [Option Start] Write I/O operations on the file descriptor shall complete as defined by synchronized I/O data integrity completion. [Option End]
// 7 : O_EXCL
// If O_CREAT and O_EXCL are set, open() shall fail if the file exists. The check for the existence of the file and the creation of the file if it does not exist shall be atomic with respect to other threads executing open() naming the same filename in the same directory with O_EXCL and O_CREAT set. If O_EXCL and O_CREAT are set, and path names a symbolic link, open() shall fail and set errno to [EEXIST], regardless of the contents of the symbolic link. If O_EXCL is set and O_CREAT is not set, the result is undefined.
// 8 :  O_NOCTTY
// If set and path identifies a terminal device, open() shall not cause the terminal device to become the controlling terminal for the process.
// 9 : O_NONBLOCK
// When opening a FIFO with O_RDONLY or O_WRONLY set:
// If O_NONBLOCK is set, an open() for reading-only shall return without delay. An open() for writing-only shall return an error if no process currently has the file open for reading.

// If O_NONBLOCK is clear, an open() for reading-only shall block the calling thread until a thread opens the file for writing. An open() for writing-only shall block the calling thread until a thread opens the file for reading.

// When opening a block special or character special file that supports non-blocking opens:

// If O_NONBLOCK is set, the open() function shall return without blocking for the device to be ready or available. Subsequent behavior of the device is device-specific.

// If O_NONBLOCK is clear, the open() function shall block the calling thread until the device is ready or available before returning.

// Otherwise, the behavior of O_NONBLOCK is unspecified.

// O_RSYNC
// [SIO] [Option Start] Read I/O operations on the file descriptor shall complete at the same level of integrity as specified by the O_DSYNC and O_SYNC flags. If both O_DSYNC and O_RSYNC are set in oflag, all I/O operations on the file descriptor shall complete as defined by synchronized I/O data integrity completion. If both O_SYNC and O_RSYNC are set in flags, all I/O operations on the file descriptor shall complete as defined by synchronized I/O file integrity completion. [Option End]
// O_SYNC
// [SIO] [Option Start] Write I/O operations on the file descriptor shall complete as defined by synchronized I/O file integrity completion. [Option End]
// O_TRUNC
// If the file exists and is a regular file, and the file is successfully opened O_RDWR or O_WRONLY, its length shall be truncated to 0, and the mode and owner shall be unchanged. It shall have no effect on FIFO special files or terminal device files. Its effect on other file types is implementation-defined. The result of using O_TRUNC with O_RDONLY is undefined.
// If O_CREAT is set and the file did not previously exist, upon successful completion, open() shall mark for update the st_atime, st_ctime, and st_mtime fields of the file and the st_ctime and st_mtime fields of the parent directory.

// If O_TRUNC is set and the file did previously exist, upon successful completion, open() shall mark for update the st_ctime and st_mtime fields of the file.

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