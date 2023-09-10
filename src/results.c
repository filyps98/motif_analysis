#include <stdio.h>
#include <stdlib.h>

//Creating the final file and entering introductory data into it
void design_result_file(char* file_name, char* motif_name, int delta, char* originateFile)
{
    FILE *fp;
    fp = fopen(originateFile,"w");
    fprintf(fp, "Graph Name: %s\n", file_name);
    fprintf(fp, "Motif Name: %s\n", motif_name);
    fprintf(fp,"Delta Value: %d\n\n", delta);
    fprintf(fp,"TIME        NUMBER OF MOTIFS \n");
    fclose(fp);
}
//Function that is responsible for writing the output result of exactBT within the final file
void writeResult(char *resultFile, char* randFile)
{
    int flag1 = 0;
    int flag2 = 0;
    char ch; 

    FILE *source;
    FILE *destination;

    source = fopen(randFile,"r");
    if (source == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    destination =fopen(resultFile,"a");

    if (destination == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    //Set of instructions to take the time duration value of the exactBT algorithm and the number of occurrences of motif
    char prev = fgetc(source);

    //Processing the file to get the values I am interested in
    while((ch = fgetc(source)) != EOF)
    {
        if(prev == ']')
            flag1 = 1;
        else if(prev == ':' && flag1 !=0)
                flag2 = 1;
            else if(prev == '\n' && flag1 !=0 && flag2 !=0)
                    {
                        flag2 = 0;
                        //Value writing
                        for(int i = 0; i < 4; i++)
                            fputc(' ',destination);
                    }
                    //Value writing
                    else if(flag1!=0 && flag2!=0 && prev !=' ')
                        fputc(prev, destination);
        prev = ch;
    }

    fputc('\n',destination);
    //closing file
    fclose(source);
    fclose(destination);
}