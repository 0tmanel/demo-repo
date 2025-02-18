#include <stdio.h>
int main()
{
    FILE *fpt;
    char text[80];
    fpt = fopen("data.txt", "r");
    //fopen("data.txt", "r"): Opens the file in read mode.
    fscanf(fpt, "%s", text);
   //fscanf(fpt, "%s", text): Reads a word from the file into text.
    printf("%s\n", text);
   //printf("%s\n", text): Prints the word.
    fclose(fpt);
   //fclose(fpt): Closes the file.
}