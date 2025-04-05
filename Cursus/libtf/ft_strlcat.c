// strlcat() appends the src string to the end of dst. It will append at most size - strlen(dst) - 1 bytes, null-terminating the result as long as size is greater than strlen(dst).
// It is designed to prevent buffer overflows by never writing beyond the size of the buffer.
//  strlcpy() and strlcat() take the full size of the destination buffer and guarantee NUL-termination if there is room.  Note that room for the NUL should be included in dstsize.
// the strlcpy() and strlcat() functions return the total length of the string they tried to create.  For strlcpy() that means the length of src.  For strlcat() that means the initial length of dst plus the length of src.
#include <stdio.h>
#include <string.h>
int ft_strlen(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
int ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
    size_t dlen = ft_strlen(dst);
    size_t slen = ft_strlen(src);
    //If dstsize is less than or equal to dlen, it means:
    //There's no space left in dst to append any characters (because dlen is already as large as or larger than dstsize).
    //So, there's no way to add the source string (src) without causing an overflow.
    if(dstsize <= dlen)
    return dstsize + slen;
    //If the destination buffer is already full (dstsize <= dlen), the function doesn't attempt to append any characters. Instead, it returns the total length it would have created if there were no size limits (i.e., dstsize + slen). This allows the caller to know that the string was truncated.
    size_t i = 0;
    size_t len = dstsize - dlen - 1;
        while (src[i] != '\0' && i < len)
        {
            dst[dlen + i] = src[i];
            //using  dlen + i is not the same as j because at j it might overwrite the content of dst
            i++;
        }
        dst[dlen + i] = '\0';

        return dlen + slen;
}
int main()
{
    int size = 20;
    char src[] = "to find you";
    char dest[20] = "i am hoping ";
    int r = ft_strlcat(dest, src, size);
    printf("%s\n", dest);
    printf("the returned value is : %d\n", r);
    if (r > size)
        printf("String truncated\n");
    else
        printf("String was fully copied\n");
}