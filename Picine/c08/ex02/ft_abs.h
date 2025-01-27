#ifndef FT_ABS2_H
#define FT_ABS2_H

#define ABS(value) ((value) < 0 ? -(value) : (value))

//#define ABS(x) ((x) < 0 ? -(x) : (x)):
//This macro uses a ternary operator (condition ? value_if_true : value_if_false) to check if x is negative.
//If x is negative, it returns -x (making it positive).
//If x is already positive (or zero), it just returns x.

//If x is negative, say x = -5, the condition (x) < 0 will be true.
//The ternary operator then executes the true branch: -(x). So, -(x) means multiply x by -1, which makes it positive: -(-5) = 5.


#endif