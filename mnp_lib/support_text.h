#include <stdio.h>
#include <stdlib.h>

/**
* Generazione del file PermutationFile con tempi randomizzati
* \param file_name percorso e nome del file da cui si prendono le prime due colonne che non devono essere cambiate 
* \param support_file percorso e nome del file di output, con i valori dei tempi che vroremmo permutati rispetto al file originale
* \param ptr puntatore al vettore di tempi
* \param len lunghezza del vettore di tempi
*/
void substitute(char *file_name, char *support_file, int **ptr, int len);


