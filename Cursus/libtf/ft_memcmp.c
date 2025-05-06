/*
The memcmp() function compares two blocks of memory and returns an integer indicating which one is greater.

For this comparison bytes at the same position from both memory blocks are compared one by one starting at position 0 until one of them does not match or the end of the block of memory has been reached. There are three possible scenarios:

If the end of the memory blocks is reached without any mismatches then the function returns zero.
At the first mismatch, if the value of the byte in the first memory block is greater then the function returns a positive number.
At the first mismatch, if the value of the byte in the second memory block is greater then the function returns a negative number.*/
#include <string.h>
#include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const char *str = (const char *)s1;
    const char *str2 = (const char *)s2;
    int i = 0;
    while (i < n && str[i] == str2[i])
    {
        if (str[i] != str2[i])
        {
            return str[i] - str2[i];
        }
        i++;
    }
    return 0;
}
int main()
{
    const void *s1 = "hello world";
    const void *s2 = "hello korld";

    int value = ft_memcmp(s1, s2, strlen(s1));
    //  int value = memcmp(s1, s2, strlen(s1)); try the original funciton to test yours
    printf("%d\n", value);
}
/*Similar to strcmp(), memcmp() compares two chunks of memory for equivalence: #include <string.h>
int memcmp (const void *s1, const void *s2, size_t n);
An invocation compares the first n bytes of s1 to s2 and returns 0 if the blocks of memory are equivalent, a value less than zero if s1 is less than s2, and a value greater than zero if s1 is greater than s2.
BSD again provides a now-deprecated interface that performs largely the same task:
    #include <strings.h>
int bcmp (const void *s1, const void *s2, size_t n);
An invocation of bcmp() compares the first n bytes of s1 to s2, returning 0 if the blocks
of memory are equivalent, and a nonzero value if they are different.
Because of structure padding (see “Other alignment concerns” on page 305 earlier in this chapter), comparing two structures for equivalence via memcmp() or bcmp() is un‐ reliable. There can be uninitialized garbage in the padding that differs between two otherwise identical instances of a structure. Consequently, code such as the following is not safe:
    /* are two dinghies identical? (BROKEN) *
int compare_dinghies (struct dinghy *a, struct dinghy *b) {
return memcmp (a, b, sizeof (struct dinghy));
}
Instead, programmers who wish to compare structures should compare each element of the structures, one by one. This approach allows for some optimization, but it’s def‐ initely more work than the unsafe memcmp() approach. Here’s the equivalent code:
    /* are two dinghies identical? *
int compare_dinghies (struct dinghy *a, struct dinghy *b) {
int ret;

if (a->nr_oars < b->nr_oars) return −1;
if (a->nr_oars > b->nr_oars) return 1;
ret = strcmp (a->boat_name, b->boat_name); if (ret)
return ret;
}
// and so on, for each member... 
*/