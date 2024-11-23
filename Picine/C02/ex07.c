#include <unistd.h>
void *ft_print_memory(void *addr, unsigned int size)
{
    if (size == 0)
    return;
    

}
int main ()
{
    void* addrese = (void*)0x1A3;
    size_t sizen = 64;
    ft_print_memory(addrese, sizen);
}