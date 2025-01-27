#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H

#define TRUE  true
#define FALSE  false
typedef enum a_bool{
    TRUE = 1,
    FALSE = 0,

}t_bool;
#define EVEN_MSG "I have an even number of arguments."
#define ODD_MSG "I have an odd number of arguments."
#define EVEN(nbr) ((nbr) % 2 == 0)
#define SUCCESS 0
// we can use just this, #define t_bool int
#include <unistd.h>

#endif

//C provides a special kind of type designed specifically for variables that have a small number of possible values. An enumerated type is a type whose values are listed (“enumerated”) by the programmer, who must create a name (an enumera- tion constant) for each of the values.