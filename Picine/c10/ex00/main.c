#include <unistd.h>
#include <fcntl.h>
int main (int argc, char *argv[])
{
    char buf[100] = "hello world";
    /*The line char *buf = "hello world";
     initializes buf as a pointer to a string literal,
      which is not the correct way to use it as a buffer for reading file content.
       String literals are immutable, so modifying the contents 
       of buf will lead to undefined behavior.*/
    int fd;
    if (argc == 1)
    {
        write(2, "File name missing\n", 18);
        return 1;
    }
    if(argc > 2)
    {
        write(2, "Too many arguments\n", 18);
        return 1;
    }
    fd = open (argv[1], O_RDONLY);//It returns a file descriptor (an integer) that
                                   // can be used for subsequent file operations 
                                   //(e.g., reading or writing).
    if(fd == -1)
    {
        write(2, "Cannot read file\n", 17);
        return 1;
    }
   //The read() function returns the number of bytes actually read. 
   //If it returns 0, it means you've reached the end of the file (EOF).
   // If it returns -1, there was an error.
    
   int result;
  //In each iteration of the loop, read() reads another chunk of 
  //data from the file (up to 100 bytes) and stores it in buf.
   while ((result = read(fd, buf, 100)) > 0)
   {
        write(1, buf, result);
       
   }
   if(result == -1)
   {
    write(2, "Cannot read file\n", 17);
    close(fd);
    return 1;
   }

    /*In a file reading context, you shouldn't use '\0' to detect the end of the file.
    The read() function will return 0 when it reaches the end of the file EOF, 
    not when it encounters a null character. 
    You should check the return value of read() 
    to determine if you've reached the end of the file.*/
   close(fd);
   return 0;
}
/*Array (char buf[100]): When you declare an array of a fixed size (e.g., char buf[100]), 
you are allocating a specific amount of memory that is modifiable.
Pointer (char *buf): When you declare a pointer (e.g., char *buf = "hello world";), 
the pointer itself is storing an address (a reference) to a memory
 location where the string literal resides, which is typically in read-only memory.*/