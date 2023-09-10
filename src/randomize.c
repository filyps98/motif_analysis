#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SFMT.h"

//Fisher-Yates permutation algorithm
void randomize(int *num, int len){ 
     int i, j, temp;
    
    //Using the SFMT randomization algorithm.
    sfmt_t sfmt;
    sfmt_init_gen_rand(&sfmt, rand());

    //Permutation cycle
     for (i = len-1; i > 0; i--) 
     { 
         //Random choice of index from those remaining
         j = (int)(ceil(sfmt_genrand_res53(&sfmt)*len)) % (i+1);

         //Array exchange
         temp = num[j];
         num[j] = num[i];
         num[i] = temp;
     }
}