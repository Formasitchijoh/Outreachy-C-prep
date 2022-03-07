/*********************************************************************************
 Write a program in C to create and store information in a text file
The outcome of this exercise is that i now underdstand that a file name is just
the same as an array of characters which could(is) an array of characters
henc i could create a file name using an array as the exercise specified aligned
and using the 
**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str[1000];
    FILE *fptr;
    
    /*******************************************************
     * The  name of a file is an array of characters 
     * reason why I am storing them in an array called fname
     * ******************************************************/

    char fname[20] = "test.txt";
    printf("\n\n Create a file (test.txt) and input text :\n");
    printf("--------------------------------\n");
    
    /***************************************************************
    The fopen function opens a file then returns a pointer to
    the specified file to fptr which can be used to manipulate the file
    ********************************************************************/
    fptr = fopen(fname,"w");

    if(fptr == NULL)
    {
        printf("Error in opening file :");
        exit(1);
    }
    /******************************************************
     * The fgets function reads a string from stdin of a specified size
     * and store it in a file stream unlike fgetc that reads characters
     *  from stdin/file stream and stores the read characters into an array
     * fprintf  prints the content of its third argument ie a file into its
     *  first using the format specifier same as for printf
     * ************************************************************************/
    
        printf("Input a sentence for the file :!");
        fgets(str,sizeof str,stdin);
        fprintf(fptr,"%s",str);
        fclose(fptr);

        printf("\n The file %s created succesfully......!!!\n\n",fname);
        
        return 0;

            
}
