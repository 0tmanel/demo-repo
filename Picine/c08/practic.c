// ############## HEADERS ##########
// #define and #include and others that we haven’t yet covered—are handled by the preprocessor, Moreover, the preprocessor can easily be misused to create programs that are almost impossible to understand.

//The behavior of the preprocessor is controlled by preprocessing directives: com- mands that begin with a # character. The #define directive defines a macro, a name that represents something else, such as a constant or frequently used expression.

//The #include directive tells the preprocessor to open a particular file and “include” its contents as part of the file being compiled.

//The input to the preprocessor is a C program, possibly containing directives. The preprocessor executes these directives, removing them in the process. The output of the preprocessor is another C program: an edited version of the original pro- gram, containing no directives. The preprocessor’s output goes directly into the compiler, which checks the program for errors and translates it to object code (machine instructions).

// most C compilers provide a way to view the output of the preprocessor. Some compilers generate preprocessor output when a certain option is specified (GCC will do so when the -E option is used). gcc -E [NAME OF THE FILE]

//Most preprocessing directives fall into one of three categories:

//■ Macro definition. The #define directive defines a macro; the #undef directive removes a macro definition.

//■ File inclusion. The #include directive causes the contents of a specified file to be included in a program.

//■ Conditional compilation. The #if, #ifdef, #ifndef, #elif, #else, and #endif directives allow blocks of text to be either included in or excluded from a program, depending on conditions that can be tested by the preprocessor.

//Besides its simple form, a macro can take parameters and behave like a function. Don’t leave a whitespace after the name of a parameterized macro because the prepro- cessor will handle the left parenthesis as the beginning of a simple macro definition.

//to creat a header file The #ifndef and #define directives are used together in C and C++ header files to prevent multiple inclusions of the same file. This is commonly referred to as an include guard.

// the #ifndef and #define work together to ensure that the content of the header file is only included once in a single translation unit. This is crucial because if a header is included multiple times, it can cause redefinition errors.



//angular brackets (<>), as in #include <stdio.h> indicate to the preprocessor that a header file is to be found in a system directory. Quotes around the header file name, as in #include "planet.h" mark it as information about a library belonging to the programmer.

//Use auto by default (no need to specify it explicitly).

//Use register for performance-sensitive variables, like loop counters.

//Use static for variables that need to persist across function calls or to limit scope to the file or function.

//Use extern for global variables shared across multiple files.

//Use typedef to create more readable type aliases.
 

 // ################STRUCT###########

 //Structure variables are declared similarly to other variables in C, but it is usually a two-step process.
//1. Define the structure.
//2. Declare the variables of the respective structure type.

//There are two methods to initialize structure variables.
/*
 **************** Method 1
After declaring a structure variable, each member is initialized individually. The dot operator is used to access the member variables. Refer to the code above in struct1.c to see how the variable struct data current is initialized after its declaration.

int main(int argc, char* argv[])
{
struct date {
                int day;
                int month;
                int year;
        };
        struct date current;
        current.day = 1;
        current.month = 11;
        current.year = 2012;
        return 0;
}
 **************** Method 2
 Structure variables can be initialized with the use of set notation. In set notation, the values are written in ordered form with a comma separating the opening and closed curly braces. The member fields get initialized with the values found in the specified order. The code below illustrates this method of initializing the structure member fields.

 int main(int argc, char* argv[])
{
struct date {
                int day;
                int month;
                int year;
        };
        struct date current = { 1, 11,  2012 };
        return 0;
}
*/
//Structure in Memory
//A structure data type variable is very similar to an array when loaded in memory. All the member fields take consecutive memory locations.
//The size of a structure variable is equivalent to the total size of all the variables it contains. 

struct book {
char title[100]; int year;
float price;
} b1, b2; 

//The b1 and b2 variables are declared as structures of the type book. If we declare all the variables we need in the structure_variable_list, the tag (i.e., book) may be omitted. However, to be able to declare variables whenever we need, our suggestion is always to name the structure and use that tag to declare variables. Alternatively, as we’ll see in the next section, we can omit the tag and use the typedef to create a synonym

/*
struct date {
    int day;
    int month; 
    int year;
};
This defines a new structure type called struct date, but it doesn't create any variables of that type. Essentially, you're saying: "Here is a new structure type struct date with three members: day, month, and year."


struct date {
    int day;
    int month; 
    int year;
} d;
This defines the same structure type as the first option, but in addition, it also creates a variable named d of type struct date. So now, d is an instance of the struct date, meaning you can use d.day, d.month, and d.year to access the members of this specific struct date.

so instead of writing struct date d ; and access the member you can use the variable d with the struct


struct date {
    int day;
    int month; 
    int year;
};
this is alone is just a type , there is no allocation in memory now , but when we do :
struct date d1, d2, d3; 
we have three objects (d1, s2, d3) of type date , and we can access this object by the name of the object, and dot and the value you want to access inside it

as for the keyword typedef, we use it to use an alias for a word :
typedef int integer;

here instead of using int , we can use: integer x = 8
*/