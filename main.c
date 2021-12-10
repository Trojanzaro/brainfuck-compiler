#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char c, file_code[9999];     // make them variables
    char *pointer = (char *)malloc(sizeof(char) * 9999); // initialize teh belt
    int counter = 0, return_counter = 0, i = 0;  //these are the params that the "code" part rests in, basically this compiler reads the entire file and THEN executes it character per character
    
    FILE *file = fopen(argv[1], "r");   
    while ((c = getc(file)) != EOF) file_code[counter++] = c; // read teh file
    fclose(file); // close teh file
    
    while ((i++) <= counter) { // `i` is the pointer for where we are in the code, this is needed because the `return_counter` can return to parts of the code for the while loops
        switch (file_code[i]) { // I don't need to explain this part, read the brainfuck documentation.
            case '>':
                (pointer)++;
                break;
            case '<':
                (pointer)--;
                break;
            case '+':
                (*pointer)++;
                break;
            case '-':
                (*pointer)--;
                break;
            case '[':
                return_counter = i;       // this....[...
            case ']':
                if (*pointer != 0) i = return_counter; else return_counter = 0; // ....]... and this were the only complicated parts in the whole project, took me like... 3 minutes to implement
                break;
            case '.':
                putc(*pointer, stdout);
                break;
            case ',':
                *pointer = getc(stdin);
                break;
        }
    } // I chose to make the compiler code exactly 42 lines long because....ya know....42
    return 0;
}