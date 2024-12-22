 //strlcat returns the total length of the string it tried to create, 
//not the length of the string that was actually copied.
//If the result fits in size bytes, strlcat returns the length of
 //the concatenated string (strlen(dest) + strlen(src)).
//If there is not enough space, it returns the total length of the string 
//that would have been created if there were enough space (i.e., strlen(dest) + 
//strlen(src)), which is helpful to detect buffer overflow risks.
 #include <stdio.h>
 #include <string.h>
 ///*
 int ft_strlen(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 } //*/
 //The primary reason for using an unsigned type (such as size_t or 
 //unsigned int) to represent sizes (like the length of strings or arrays)
  //is that sizes can never be negative. A string or 
  //buffer size is always a non-negative integer.
//*********************************************************** */
  //size indicates the total size of the buffer dest (including the 
//space needed for the null terminator).strlcat will append the src string 
//to dest, but it ensures that no more than size - 1 characters from src are 
//copied, leaving space for the null terminator (\0).
//If dest does not have enough space to hold the full concatenated string, 
//the function will truncate the source string and only copy as much as will fit.
 
 unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
 {
    unsigned int  slen = ft_strlen(src);
      unsigned int  dlen;
    //unsigned int dlen = ft_strlen(dest);
   unsigned int i = 0;
   while (dest[i] != '\0')
   {
    i++;
   }
   dlen = i;

  if(size == 0 || dlen >= size)
  {
    return slen + dlen;
  }
        unsigned int j = 0;
        while (src[j] != '\0' && j < size - dlen - 1)
        {
            dest[dlen + j] = src[j];
            j++;
        }
        dest[j] = '\0';
       
    
        return dlen + slen;
 } 
 int main ()
 {
    char dest[20] = "helloo";
    char src[] = " world";
    unsigned int size = sizeof(dest);
  
  unsigned int ret = ft_strlcat(dest, src, size);
   //unsigned int ret = strlcat(dest, src, size);
   printf("%d\n", ret);

 }
