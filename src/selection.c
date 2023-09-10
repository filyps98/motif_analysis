#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//input data selection as Dataset name, Motif, delta value
int selection(char *file_name, char ***motif_list, int *delta)
{
    DIR *d;
    DIR *s;
    int count = 0;
    int length = 0;
    struct dirent *dir;
    d = opendir("__/datasets/");

    //controllo
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            //the readdir function also prints . and .., we want to avoid that
            if(strcmp(dir->d_name,".") && strcmp(dir->d_name,".."))
                printf("%s\n", dir->d_name);
        }
        closedir(d);
    }

    //I enter the dataset from input
    printf("\n\nChoose between the files with .txt extension:  ");
    scanf("%s",file_name);
    
    //I investigate the directory where all the motifs are present to get their names
    s = opendir("__/motifs/");

    //controlling
    if(s){
    *motif_list = NULL;
    dir = readdir(s);

    //I count the number of motifs in the directory
    while(dir != NULL){
        if(strcmp(dir->d_name,".") && strcmp(dir->d_name,".."))
            count++;
        dir = readdir(s);
        
    }

    //return to top of file list
    rewinddir(s);
    dir = readdir(s);

    //I allocate dynamic memory that will contain the names of all motifs
    *motif_list = calloc(count, sizeof(char *));

    count = 0;

    //until there are no more files to read imagine the string in motif_list
    while(dir != NULL){
        if(strcmp(dir->d_name,".") && strcmp(dir->d_name,".."))
            (*motif_list)[count++] = strdup(dir->d_name);
        dir = readdir(s); 
    }

    //closing the file
    closedir(s);
    
    }

    //choosing delta value
    printf("\n\nInsert the delta value: ");
    scanf("%d", delta);

    //return the number of elements in the motif directory
    return count;

}
