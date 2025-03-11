//Reversing the bits of an octet (a byte, 8 bits) means flipping the order of the bits so that the least significant bit (LSB) becomes the most significant bit (MSB) and vice versa.
#include <stdio.h>
unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char reversed = 0;
    int i = 0;
    while ( i < 8) {
        reversed = (reversed << 1) | (octet & 1);  // Shift left and add LSB
        octet >>= 1;  // Shift right to process the next bit
        i++;
    }
    return reversed;
}
int main ()
{
    unsigned char ret =  reverse_bits(10);
    printf("%d\n", ret);
}