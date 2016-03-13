# FunctionsFinder Version 1.0 13/03/2016

GENERAL USAGE NOTES
--------------------
The program finds all descriptions of functions in program file that have been commented in Doxygen style. 
Examples of these comments:
/** \func int main() */
/**
\func void show()
*/

Example of work
----------------
After compiling .cpp file the user should open a command line and enter the name of .exe file and the of the name of program file
with comments in Doxygen style:
<.exe> <program file> 
If it has been entered correctly, the program will show the following:
<index number>. <description of function>
...
If program has not shown anything, there are not any descriptions of functions.

---------------------------
E-mail: lisa-bella97@mail.ru
