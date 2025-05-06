#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *arr, int start, int end, int perms[4][4], int *count)
{
    if (*count == 4)  // Stop when we have 4 permutations
        return;

    if (start == end)
    {
        // When a complete permutation is generated, store it in perms
        for (int i = 0; i < 4; i++)
        {
            perms[*count][i] = arr[i];  // Store current permutation in the perms array
        }
        (*count)++;
        return;
    }
    
    for (int i = start; i <= end; i++)
    {
        swap(&arr[start], &arr[i]);   // Swap elements to generate permutations
        permute(arr, start + 1, end, perms, count);  // Recursively permute the rest
        swap(&arr[start], &arr[i]);  // Backtrack by swapping back
    }
}

void generate_permutations(int perms[4][4])
{
    int arr[4] = {1, 2, 3, 4};  // The numbers you want to permute
    int count = 0;
    permute(arr, 0, 3, perms, &count);  // Call permute to generate permutations
}
char* parse_input(char* str)
{
    char* string = malloc((16 + 1) * sizeof(char));
    int i = 0;
    int index = 0;
    int j = 0;
    while(str[i] != '\0')
    {
        if(str[i] >= '1' && str[i] <= '4')
        {
            if(j >= 16)
            {
                free(string);
                return NULL;
            }
            string[j++] = str[i];
        }
        if(!(str[i] >= '1' && str[i] <= '4' || str[i] == ' '))
        {
            return NULL;
        }
        i++;
    }
    if(j != 16)
    {
        free(string);
        return NULL;
    }
     string[j] = '\0';
    return string;
}
int main(int argc, char** av)
{
    if(argc != 2)
   {
    write(1, "Error\n", 6);
    return 1;
   }
   char *string = parse_input(av[1]);
   if(!string)
   {
     write(1, "Error\n", 6);
     return 1;
   }
   int perms[4][4];  // Declare the array to store the permutations
    generate_permutations(perms); 

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", perms[i][j]);
        }
        printf("\n");
    }
    
}