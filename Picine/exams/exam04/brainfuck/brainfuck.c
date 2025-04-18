#include <unistd.h>
#include <stdlib.h>
// void brainfuck(char *code)
// {
//     char memory[30000] = {0};
//     char *ptr = memory;
//     int i = 0;

//     while (code[i])
//     {
//         if (code[i] == '>')
//             ptr++;
//         else if (code[i] == '<')
//             ptr--;
//         else if (code[i] == '+')
//             (*ptr)++;
//         else if (code[i] == '-')
//             (*ptr)--;
//         else if (code[i] == '.')
//             write(1, ptr, 1);
//         else if (code[i] == ',')
//             read(0, ptr, 1);
//         else if (code[i] == '[')
//         {
//             if (*ptr == 0)
//             {
//                 int loop = 1;
//                 while (loop)
//                 {
//                     i++;
//                     if (code[i] == '[')
//                         loop++;
//                     if (code[i] == ']')
//                         loop--;
//                 }
//             }
//         }
//         else if (code[i] == ']')
//         {
//             if (*ptr != 0)
//             {
//                 int loop = 1;
//                 while (loop)
//                 {
//                     i--;
//                     if (code[i] == '[')
//                         loop--;
//                     if (code[i] == ']')
//                         loop++;
//                     // When you're at a ] and need to jump back to the matching [, you may be inside nested loops, so you need to:

//                     // Walk backward through the code (i--)

//                     // Count how many unmatched brackets you've passed

//                     // Stop when you've matched all nested levels
//                 }
//             }
//         }
//         i++;
//     }
// }








void brainfuck(char*str)
{
    char memory[2024] = {0};
    char* ptr = memory;
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '>')
        {
            ptr++;
        }else if(str[i] == '<')
        {
            ptr--;
        }else if(str[i] == '+')
        {
            (*ptr)++;
        }else if(str[i] == '-')
        {
            (*ptr)--;
        }else if(str[i] == '.')
        {
            write(1, ptr, 1);
        }else if(str[i] == '[')
        {
            if(*ptr == 0)
            {
                int loop = 1;
                while(loop)
                {
                    i++;
                    if(str[i] == '[')
                    {
                        loop++;
                    }
                    if(str[i] == ']')
                    {
                        loop--;
                    }
                }

            }
        }
        else if(str[i] == ']')
        {
            if(*ptr != 0)
            {
                int loop = 1;
                while(loop)
                {
                    i--;
                    if(str[i] == '[')
                    {
                        loop--;
                    }if(str[i] == ']')
                    {
                        loop++;
                    }
                }
            }
        }
        i++;
    }
}
int main(int argc, char **av)
{
    brainfuck(av[1]);
   // write(1, "\n", 1);
}