#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>

//function that replaces the time vector to the third column of the support file, leaving the first two 
//invariant
void substitute(char *file_name, char *support_file, int **ptr, int len)
{
    
    FILE *source, *destination;
    char ch;
    int flag_space = 0;
    int i = 0;

    //Open the original file for reading
    source = fopen(file_name, "r");

    if (source == NULL)
    {
        printf("Lettura non riuscita, premi qualunque tasto per uscire\n");
        exit(EXIT_FAILURE);
    }

    //Opening the support file in writing
    destination = fopen(support_file, "w");

    if (destination == NULL)
    {
      fclose(source);
      printf("Lettura non riuscita, premi qualunque tasto per uscire\n");
      exit(EXIT_FAILURE);
    }

    ch = fgetc(source);

    //Processing in reverse of extracting values, I store the new values present in the memory space dedicated to times in the new file.
    while (i < len)
      {
          fputc(ch, destination);


          if(ch == ' ' && flag_space == 0)
                {
                    flag_space = 1;
                }

            else if(ch == ' ' && flag_space == 1)
                    {
                        flag_space = 0;
                        //put in n the value of the integer stored in the i-th cell
                        int n = *(*ptr + i);
                        //calculate an upper bound for the size of the character array that will store my number
                        int ENOUGH;
                        if(n >= 10)
                            ENOUGH = (int)((ceil(log10(n))+1)*sizeof(char));
                        else ENOUGH = 2;
                        char str[ENOUGH];
                        //integer to string conversion
                        sprintf(str, "%d", n);
                        //Writing the string in the third column.
                        fprintf(destination, "%s", str);
                        
                        //Ahead with the next value
                        ++i;
                        //If I haven't reached the end of the vector, I go to caporiga and consume the characters of the
                        //original file up to \n
                        if(i != len)
                        {   fputc('\n',destination);
                            char spar = fgetc(source);
                            while(spar != '\n')
                                spar = fgetc(source);
                        }
                    }
            ch = fgetc(source);
        }

   fclose(source);
   fclose(destination);

}