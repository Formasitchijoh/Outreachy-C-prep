/**********************************************
 * This program copies content from a file source_fp
 * to a destination file dest_fp using some file functions
 * **********************************************************/

#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************
int main(int argc, char *argv[])
{
    FILE*source_fp, *dest_fp;
    int ch;

    if(argc != 3)
    {
        ********************************************************************
        test if the file names are given during runtime by the user
        * uses the fprintf function to write a constant string into stderr
        file stream 
        *********************************************************************
        fprintf(stderr ,"usage: fcopy source dest\n");
        exit(EXIT_FAILURE);
    }

    if((source_fp = fopen(argv[1],"rb")) == NULL)
    {            
        ***********************************************************************
         * fprintf here contains 3 argument the command line argument which 
         * contains the file name or its content will be written into the stderr 
         * and the format specifier shows that there are strings which will be written
         * ***********************************************************************
        fprintf(stderr,"can't open %s\n",  argv[1]);
        exit(EXIT_FAILURE);
    }

    if((dest_fp = fopen(argv[2],"wb")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        fclose (source_fp);
        exit(EXIT_FAILURE);
      }

     while((ch = getc(source_fp)) != EOF)
         putc(ch,dest_fp);

    fclose(source_fp);
     fclose(dest_fp);
     return 0;


}
*********************************************************************************************************/
int main(int argc, char * argv[])
{
    FILE *source_fp, *dest_fp;

    int ch;

    if(argc != 3)
    {
        fprintf(stderr, "usage : fcopy source dest\n");
        exit(EXIT_FAILURE);
    }

    if((source_fp = fopen(argv[1], "rb")) == NULL)
     {  
         /********************************************************************
         * Note that fopen returns a pointer to the source_fp
         * reason why its return value can be compared to the NULL pointer
         *******************************************************************/
         fprintf(stderr, "can't open %s\n", argv[1]);
         exit(EXIT_FAILURE);
     }
     
     if((dest_fp = fopen(argv[2],"a+")) == NULL)
     {git s
         fprintf(stderr, "can't open %s\n",argv[2]);
         exit(EXIT_FAILURE);
         fclose(source_fp);
     }

     while((ch = getc(source_fp)) != EOF)
        putc(ch, dest_fp);

    fclose(source_fp);
    fclose(dest_fp);
    return 0;


}