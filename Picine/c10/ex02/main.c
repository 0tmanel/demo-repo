/*#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#define BUF_SIZE 1024 
int count_newlines(char *buf, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (buf[i] == '\n')
        {
            count++;
        }
    }
    return count;
}
int main(int argc, char *argv[])
{
    char *buf = malloc(BUF_SIZE * sizeof(char));
    if (buf == NULL)
    {
        return 1;
    }
    int fd;
    int result;
    int i = 1;
    if (argc == 1)
    {
        write(2, "File missing\n", 13);
        return 1;
    }
    while (argc > i)
    {
        char *base = basename(argv[i]);
        fd = open(argv[i], O_RDONLY);
        if (fd == -1)
        {
            char *mssg = strerror(errno);
            write(2, "bash: ./", 8);
            write(2, base, strlen(base));
            write(2, ": ", 3);
            write(2, mssg, strlen(mssg));
            write(2, "\n", 1);
        }
        else
        {
             while ((result = read(fd, buf, 1000)) > 0)
             {
                 write (1, buf, result);
             }
            off_t file_size = lseek(fd, 0, SEEK_END);
            if (file_size == -1)
            {
                char *mssge = strerror(errno);
                write(2, "Error getting file size: ", 25);
                write(2, mssge, strlen(mssge));
                write(2, "\n", 1);
            close(fd);
            continue;
            }
        
        off_t offset = file_size - 1;
        int lines = 0;
        while (offset >= 0 && lines < 10)
        {
            int to_read = (offset < BUF_SIZE) ? offset + 1 : BUF_SIZE;
            lseek(fd, offset - to_read + 1, SEEK_SET); // Set the file pointer
            int result = read(fd, buf, to_read);

            if (result == -1)
            {
                char *mssg = strerror(errno);
                write(2, "Error reading file: ", 20);
                write(2, base, strlen(base));
                write(2, ": ", 3);
                write(2, mssg, strlen(mssg));
                write(2, "\n", 1);
                break;
            }
            int newline_count = count_newlines(buf, result);
            lines += newline_count;

            // Print the buffer in reverse order
            for (int j = result - 1; j >= 0; j--)
            {
                write(1, &buf[j], 1);
            }

            // Adjust the offset for the next iteration
            offset -= to_read;
        }
        close(fd);
        }
        i++;
    }
    free(buf);
    return 0;
}*/
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE 1024  // Buffer size for reading data
#define NUM_LINES 10   // Number of lines to display (like the "tail" command)

// Function to count the number of newlines in the buffer
int count_newlines(char *buf, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buf[i] == '\n') {
            count++;
        }
    }
    return count;
}

// Function to print the last 10 lines (or less, if fewer than 10 lines exist)
void print_last_lines(char **lines, int line_count) {
    for (int i = 0; i < line_count; i++) {
        write(1, lines[i], strlen(lines[i]));
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // No file argument provided, print error message
        write(2, "File missing\n", 13);
        return 1;
    }

    // Allocate memory for reading data
    char *buf = malloc(BUF_SIZE * sizeof(char));
    if (buf == NULL) {
        return 1; // Error in malloc
    }

    int i = 1;
    while (argc > i) {
        char *base = basename(argv[i]);
        int fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            // Error opening file
            char *mssg = strerror(errno);
            write(2, "bash: ./", 8);
            write(2, base, strlen(base));
            write(2, ": ", 3);
            write(2, mssg, strlen(mssg));
            write(2, "\n", 1);
        } else {
            off_t file_size = lseek(fd, 0, SEEK_END); // Get the size of the file
            if (file_size == -1) {
                char *mssg = strerror(errno);
                write(2, "Error getting file size: ", 25);
                write(2, mssg, strlen(mssg));
                write(2, "\n", 1);
                close(fd);
                continue;
            }
            int byte_count = 0;
if (argc == 3 && strcmp(argv[1], "-c") == 0) {
    byte_count = atoi(argv[2]);
}

            // Allocate memory to store up to NUM_LINES lines
            char **lines = malloc(NUM_LINES * sizeof(char*));
            if (lines == NULL) {
                write(2, "Memory allocation failed\n", 24);
                close(fd);
                continue;
            }

            // Initialize the lines array
            for (int j = 0; j < NUM_LINES; j++) {
                lines[j] = NULL;
            }

            off_t offset = file_size - 1;
            int line_count = 0;
            int line_length = 0;
            int buf_index = BUF_SIZE - 1;
            int to_read = BUF_SIZE;

            // Start reading from the end of the file
            while (offset >= 0 && line_count < NUM_LINES) {
                // Move the file pointer backwards and read into the buffer
                if (offset - BUF_SIZE + 1 >= 0) {
                    to_read = BUF_SIZE;  // Read full buffer
                } else {
                    to_read = offset + 1;  // Read the remaining part of the file
                }

                lseek(fd, offset - to_read + 1, SEEK_SET);  // Set the file pointer
                int result = read(fd, buf, to_read);

                if (result == -1) {
                    char *mssg = strerror(errno);
                    write(2, "Error reading file: ", 20);
                    write(2, base, strlen(base));
                    write(2, ": ", 3);
                    write(2, mssg, strlen(mssg));
                    write(2, "\n", 1);
                    break;
                }

                // Traverse the buffer in reverse and extract lines
                for (int j = result - 1; j >= 0; j--) {
                    // If newline, it's the end of a line
                    if (buf[j] == '\n') {
                        if (line_count < NUM_LINES) {
                            // Allocate memory for the line and copy it into the lines array
                            lines[line_count] = malloc(line_length + 1);
                            if (lines[line_count] != NULL) {
                                memcpy(lines[line_count], &buf[j + 1], line_length);
                                lines[line_count][line_length] = '\0';  // Null terminate the string
                                line_count++;
                            }
                        }
                        line_length = 0;  // Reset line length for the next line
                    } else {
                        line_length++;  // Increment line length
                    }
                }

                offset -= to_read;  // Adjust the offset for the next iteration
            }

            // Print the last 10 lines
            print_last_lines(lines, line_count);

            // Free the allocated memory for the lines
            for (int j = 0; j < line_count; j++) {
                free(lines[j]);
            }
            free(lines);

            // Close the file after reading
            close(fd);
        }
        i++;
    }

    // Free the buffer memory
    free(buf);
    return 0;
}
