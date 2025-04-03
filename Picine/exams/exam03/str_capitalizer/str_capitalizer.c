#include <unistd.h>

int main(int argc, char **av)
{
    int j = 1;
    int flag = 0;
    if(argc > 1)
    {
    while (j < argc)
    {
         int i = 0;
        while (av[j][i] != '\0')
        {
            if (i == 0 || (av[j][i - 1] == ' ' || av[j][i - 1] == '\t' && flag == 0))
            {
                if (av[j][i] >= 'a' && av[j][i] <= 'z')
                {
                    av[j][i] -= 32;
                }
                flag = 1;
            }
            else if (av[j][i] >= 'A' && av[j][i] <= 'Z' && flag == 1)
            {
                av[j][i] += 32;
            }
            else if (av[j][i] == ' ' || av[j][i] == '\t')
            {
                while (av[j][i] == ' ' || av[j][i] == '\t')
                {
                    write(1, &av[j][i], 1);
                    i++;
                }
                i--;
                flag = 0;
            }

            write(1, &av[j][i], 1);
            i++;
        }
        write(1, "\n", 1);
        j++;
    }
    }
    else{
        write(1, "\n", 1);
    }
}
/*
#include <stdio.h>
char* capitalizeTitle(char* title) {
         int i = 0;
         int flag = 0;
        while (title[i] != '\0')
        {
            if (i == 0 || (title[i - 1] == ' ' || title[i - 1] == '\t' && flag == 0))
            {
                if (title[i] >= 'a' && title[i] <= 'z')
                {
                    title[i] -= 32;
                }
                flag = 1;
            }
            else if (title[i] >= 'A' && title[i] <= 'Z' && flag == 1)
            {
                title[i] += 32;
            }
            else if (title[i] == ' ' || title[i] == '\t')
            {
                while (title[i] == ' ' || title[i] == '\t')
                {
                    i++;
                }
                i--;
                flag = 0;
            }
            i++;
        }
        return title;
}  */