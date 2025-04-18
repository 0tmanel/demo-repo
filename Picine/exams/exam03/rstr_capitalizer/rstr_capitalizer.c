#include <unistd.h>
/*
void rstr_capitalizer(char *str)
{
    int i = 0;
    int j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            int l = i - 1;
            while (j <= l)
            {
                if (str[l] >= 'a' && str[l] <= 'z')
                {
                    str[l] -= 32;
                }

                write(1, &str[j], 1);
                j++;
            }
            while (str[i] == ' ' || str[i] == '\t')
            {
                write(1, &str[i], 1);
                i++;
            }
            i--;
            j = i + 1;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
        i++;
    }
    int l = i - 1;
    if (str[i] == '\0')
    {
        while (j <= l)
        {
            if (str[l] >= 'a' && str[l] <= 'z')
            {
                str[l] -= 32;
            }

            write(1, &str[j], 1);
            j++;
        }
    }
}
*/
void	rstr_capitalizer(char *s)
{
	int		i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if ((s[i] >= 'a' && s[i] <= 'z') && (s[i + 1] == '\t' || s[i + 1] == ' ' || s[i + 1] == '\0'))
			s[i] -= 32;
		i++;
	}
	write(1, s, i);
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        int i = 0;
        while (i < argc)
        {
            rstr_capitalizer(argv[i]);
            
            i++;
        }
    }
    else{
        write(1, "\n", 1);
    }
}