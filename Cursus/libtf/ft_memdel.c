#include <stdio.h>
void ft_memdel(void **ap)
{
    //if (ap) → make sure the pointer-to-pointer is valid.
    //if (*ap) → make sure the memory we're about to free is valid.
    if (ap && *ap)
    {
        free(ap);
        ap = NULL;
    }
}
int main ()
{
    char *str = malloc(10);
ft_memdel((void **)&str);
//str is a pointer to char*, and when we pass &str we pass the address of the pointer so it becomes char**

}