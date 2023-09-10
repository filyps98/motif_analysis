#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>

int getVector(char *file_name, int ** num, int len)
{
    FILE *fp;
    int flag_space = 0;
    int i = 0;
    
    fp = fopen(file_name, "r"); // read mode

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    

    int character = fgetc(fp);

    /*
      Process to extract time values, convert them to int and place them in the dedicated memory space
      Flags are used to check when I get to the second space
     */
    while(character != EOF)
        {

            if(character == ' ' && flag_space == 0)
                {
                    flag_space = 1;
                    character = fgetc(fp);
                }

            else if(character == ' ' && flag_space == 1)
                    {
                        flag_space = 0;
                        char str[13];
                        int index = 0;

                        character = fgetc(fp);

                        //I store the characters in the last column in a string
                        while(character != '\n' && character != EOF)
                        {
                            str[index] = character;
                            ++index;
                            character = fgetc(fp);
                        }

                        //I end the sequence of characters with this escape sequence
                        str[index] = '\0';
                        
                        //String to integer conversion
                        *(*num + i) = atoi(str);
                        //increase the number of integers in the vector by 1
                        ++i;
                        

                        //If the vector is filled by 9/10 I allocate more memory dynamically, and copy all
                        //the values, then I free the memory
                        if(i > ceil((9 * len)/10))
                            {
                                int *dest = (int *)calloc(2*len,sizeof(int));
                                memcpy(dest, *num, len * sizeof(int));
                                len = 2*len;
                                free(*num);
                                *num = dest;
                            }

                    }
                    else character = fgetc(fp);
            
        }


    fclose(fp);
    return i;

}

