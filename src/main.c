#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <sys/time.h>
#include "modifier_text.h"
#include "support_text.h"
#include "randomize.h"
#include "selection.h"
#include "results.h"

/**
 * \brief  The main will have to deal with iterating the program on all motifs
available. These will be selected one by one and always used on the same graph. The main will
will be mainly devoted to calling the functions that implement the different design steps,
as well as iterating the procedure for permuting the vector and revaluing the count on the
modified dataset.
 */

int main()
{

    struct timeval start, end;

    int BUFFER = 400;
    char buf1[BUFFER];
    

    char file_name[30]; 
    char** motif_list;
    int *delta = malloc(sizeof(int)); 

    //Input data selection such as Dataset name, Motif, delta value and number of permutations

    int num_motif = selection(file_name, &motif_list, delta);

    gettimeofday(&start, NULL);

    //Path and file definition series
    char dataset_path[60] = "__datasets/";
    char support_file[] = "__PermutationFile.txt__";
    //Enter the path to the project
    char project_path[] = "cd _____________________________________";
    char motif_path[] = "__/motifs/";
    char exactBT_path[] = "__/exact/";
    char result[50];
    char temporResult[] ="__TemporalResultFile.txt__";


    //Concatenate a path to reach the dataset specified by input
    strcat(dataset_path, file_name);
    
    //I create memory space that will contain the vector of time values
    int len = 10;
    int * l = (int*)calloc(len, sizeof(int));
    int **ptr = &l;

    //Function that extracts the vector of time values
    len = getVector(dataset_path, ptr, len);

    for(int index = 0; index < num_motif; index++)
    {
        //I create the path and file name that will contain the final result
        sprintf(result,"__Result_%s", motif_list[index]);

        //I save the chosen work data to the file that will eventually carry the final result
        design_result_file(file_name, motif_list[index], *delta, result);

        //I create command string for starting exactBT via system and saving in TemporalResultFile.txt of results
        snprintf(buf1, sizeof(buf1), "%s%s%s%s%s%s%s%s%d%s",project_path,exactBT_path," && ./exactBT -i:../../../datasets/",file_name, " -m:",motif_path,motif_list[index]," -delta:", *delta, "> TemporalResultFile.txt");
        system(buf1);

        //I write the result in the first line
        writeResult(result,temporResult);
        //I remove the temporary file
        remove(temporResult);

        //Randomization cycles
        for(int i = 0; i < 500; i++)
        {
            char buffer[300];

            //Randomization
            randomize(*ptr, len);

            //PermutationFile generation with randomized times
            substitute(dataset_path, support_file, ptr, len);

            //Results saved in TemporalResultFile.txt of the graph with randomized times
            snprintf(buffer, sizeof(buffer), "%s%s%s%s%s%s%s%d%s",project_path,exactBT_path," && ./exactBT -i:PermutationFile.txt", " -m:",motif_path,motif_list[index]," -delta:",*delta, "> TemporalResultFile.txt");
            system(buffer);

            //I write down the results
            writeResult(result,temporResult);

            //I remove files to save memory
            remove(temporResult);
            remove(support_file);
        }

    }
        //Releasing dynamically allocated memory
        free(*ptr);
        free(delta);
        free(*motif_list);

        gettimeofday(&end, NULL);

        double time_taken = end.tv_sec + end.tv_usec / 1e6 - start.tv_sec - start.tv_usec / 1e6;

        printf("\n\nTIME OF EXECUTION PROGRAM: %f seconds \n", time_taken);
}