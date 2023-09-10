#include <dirent.h>
#include <string.h>
#include <stdio.h>
/**
 * Algoritmo di selezione input
 * @param file_name: puntatore al nome del dataset che andremo a restituire
 * @param motif_list: triplo puntatore che ci permetterà di avere l'elenco di tutti i motif in una directory
 * @param delta: puntatore a valore di delta necessario per la computazione dell'algoritmo exactBT
 * @return intero che rappresenta il numero di motif nella directory
*/
int selection(char *file_name, char ***motif_list, int *delta);