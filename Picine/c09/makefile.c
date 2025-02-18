//“The make program is intended to automate the mundane aspects of transforming source code into an executable. The advantages of make over scripts is that you can specify the relationships between the elements of your program to make, and it knows through these relationships and timestamps exactly what steps need to be redone to produce the desired program each time. ”

//“make defines a language for describing the relationships between source code, intermediate files, and executables. It also provides features to manage alternate configurations, implement reusable libraries of specifications, and parameterize processes with user-defined macros. ”

//“Here is a makefile to build the traditional "Hello, World" program:

//hello: hello.c
 //       gcc hello.c -o hello
//To build the program execute make by typing:

//$make”

/*
“Essentially a makefile contains a set of rules used to build an application. The first rule seen by make is used as the default rule. A rule consists of three parts: the target, its prerequisites, and the command(s) to perform:

target: prereq
               1 
               prereq
               2
               commands
The target is the file or thing that must be made. The prerequisites or dependents are those files that must exist before the target can be successfully created. And the commands are those shell commands that will create the target from the prerequisites.”
 

 “foo.o: foo.c foo.h
        gcc -c foo.c
The target file foo.o appears before the colon. The prerequisites foo.c and foo.h appear after the colon. The command script usually appears on the following lines and is preceded by a tab character.

When make is asked to evaluate a rule, it begins by finding the files indicated by the prerequisites and target. If any of the prerequisites has an associated rule, make attempts to update those first. Next, the target file is considered. If any prerequisite is newer than the target, the target is remade by executing the commands. Each command line is passed to the shell and is executed in its own subshell. If any of the commands generates an error, the building of the target is terminated and make exits. One file is considered newer than another if it has been modified more recently.”


■ Each command in a makefile must be preceded by a tab character, not a series of spaces. (In our example, the commands appear to be indented eight spaces, but it’s actually a single tab character.)
■ A makefile is normally stored in a file named Makefile (or makefile). When the make utility is used, it automatically checks the current directory for a file with one of these names.
■ To invoke make, use the command

make target

where target is one of the targets listed in the makefile. To build the justify executable using our makefile, we would use the command
make justify
■ If no target is specified when make is invoked, it will build the target of the
first rule. For example, the command
make
will build the justify executable, since justify is the first target in our makefile. Except for this special property of the first rule, the order of rules in a makefile is arbitrary.

*/
//justify: justify.o word.o line.o
       // gcc -o justify justify.o word.o line.o
//The first line states that justify depends on the files justify.o, word.o, and line.o; if any one of these three files has changed since the program was last built, then justify needs to be rebuilt. The command on the following line shows how the rebuilding is to be done (by using the gcc command to link the three object files).

//The first line in each rule gives a target file, followed by the files on which it depends. The second line is a command to be executed if the target should need to be rebuilt because of a change to one of its dependent files. 

//clean rmove only object file
//The fclean target is a more aggressive version of clean. It removes all generated files,

//The "all" target is often used as a default target in Makefiles, so that when the user runs make without specifying a particular target, the "all" target will be executed by default.
