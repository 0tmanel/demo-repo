 #include <stdio.h>
 int sort(int num1, int num2)
 {
    if(num1 < num2)
    {
        return -1;
    }else if(num1 == num2)
    return 0;
    else
    return 1;
 }
 int ft_is_sort(int *tab, int length, int(*f)(int, int))
 {
    int i = 0;
    int j = i + 1;
    while (j < length)
    {
            if(f(tab[i], tab[j]) >= 0)
            {
                return 0;
            }
        j++;
        i++;
    }
    return 1;
 }
 int main()
 {
    int tab[] = {1, 2, 3, 4, 5};
    int length = 5;
   printf("%d\n", ft_is_sort(tab, length, &sort));
 }