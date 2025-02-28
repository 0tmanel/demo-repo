#include <unistd.h>
void	print_bits(unsigned char octet)
{
    char arr[9];
    arr[8] = '\0';
    int i = 7;
   
    while (octet != 0)
    {
        arr[i] = octet % 2 + '0';
       octet /= 2;
        i--;
    }
    //octet % 2 gives the least significant bit (LSB) of octet.
    //+ '0' converts it into a character ('0' or '1').
    //arr[i] = ... stores this character at position i in the array.
   //octet /= 2; shifts octet one bit to the right, moving to the next bit.
   //i-- moves left in the array, so we store the bits from right to left.
   
    while(i >= 0)
    {
        arr[i] = '0';
        i--;
    }
   write(1, arr, 8);

}
int main ()
{
    print_bits(34);
    write(1, "\n", 1);
}