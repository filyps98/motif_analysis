#include <stdio.h>
#include <stdlib.h>

/**
 * Organizzo un'intefaccia nel file riassuntivo di output con nome del dataset e del motif usato, delta usata
 * @param file_name: nome del grafo
 * 
 * @param motif_name: nome del motif usato
 * 
 * @param delta: valore di delta usato per la computazione
 * 
 * @param originateFile: nome del file su cui andremo a scrivere i risultati finali
 */
void design_result_file(char* file_name, char* motif_name, int delta, char* originateFile);

/**
 * Funzione usata per scrivere i risultati nel file finale
 * 
 * @param resultFile: file che contiene l'output dell'algoritmo exactBT
 * 
 * @param OriginalFile: file finale su cui vado a scrivere il numero di occorrenze di un motif e il running time dell'algoritmo exactBT
 */
void writeResult(char *resultFile, char* OriginalFile);
