  #include <stdio.h>
  int is_prime(int nb)
  {
    if(nb == 0 || nb == 1)
    return 0;
    long n = nb;
    long i = 2;
    while (i * i <= n)
    {
        if(n % i == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
  int ft_find_next_prime(int nb)
  {
     if (nb <= 1)
        return 2; //the next prime after 0 and 1 is 2
        //we do not need to use long here, because the function is_prime already check
    while (1)
    {
    if(is_prime(nb))
    {
        return nb;
    }
    nb++;
    }
    return 0;
  }
  int main ()
  {
    int number = ft_find_next_prime(0);
    printf("%d\n", number);
  }