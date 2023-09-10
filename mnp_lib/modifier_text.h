#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Funzione che estrae il vettore di valori temporali dal file che rappresenta il grafo
 * @param file_name percorso e nome del file che conteine il grafo che andremo a manipolare
 * 
 * @param num doppio puntatore ad un vettore vuoto in cui verranno inseriti i valori temporali
 * 
 * @param len lunghezza iniziale del vettore
 * 
 * @return lunghezza del nuovo vettore di tempi
 */
int getVector(char *file_name, int ** num, int len);
