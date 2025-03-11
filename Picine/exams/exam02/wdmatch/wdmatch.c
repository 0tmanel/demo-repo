 #include <unistd.h>
 int ft_strlen(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
 void wdmatch(char*str1, char*str2)
 {
    int i = 0;
    int j = 0;
    int index = 0;
    while (str1[i] != '\0' )
    {
        while (str2[j] != '\0')
        {
            if(str1[i] == str2[j])
            {
                index++;
                j ++;
                break;
            }
            j++;
        }
        i++;
    }
    if(index == ft_strlen(str1))
    {
        write(1, str1, ft_strlen(str1));   
      write(1, "\n", 1);
    }
     write(1, "\n", 1);
 }
int main (int argc, char **argv){
    if(argc == 3)
    wdmatch(argv[1], argv[2]);
    else {
        write(1, "\n", 1);
    }

}