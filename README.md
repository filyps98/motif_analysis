# Motif Analysis
## Goal of the Project
This program has the aim of permuting the temporal values within a given graph and subsequently calculating the motif occurrence counts. Permutation represents a crucial step in the experiment because it allows verifying whether a change in the temporal structure of the graph and, consequently, in the nature of relationships between different nodes, leads to a change in the calculation of the number of instances. The randomized permutation of the original graph will be iterated numerous times to ensure reliability in the scale of the count, which will then be compared to the count value recorded in the original network. From the values obtained in this comparison, it can be determined whether the nature of the dataset is closely linked to its structure and whether changing the temporal characteristic of the network also modifies its content and intrinsic meaning.

### Heads up
This program is used as support for a counting motif program, which will not be inserted in this repository because it is currently reserved.

The program requires the use of a Linux operating system.

## Set-up
1. Insert your path into the "project_path" variable
   located in MAIN.C: The path should be identical to the one
   you would use to access this folder from the terminal. The
   path should be preceded by 'cd'.

2. To run the program, type "MAKE RUN" in the terminal
   from this folder
   (after compiling the MAKEFILE, also located in the same folder).

3. It is recommended to adjust the number of permutations
   if you want to reduce execution time, especially for large datasets.


## ADDITIONAL INFORMATION:

1. The results of the program for each type of motif are
  located in the "Result" folder.
2. The "motifs" folder
  contains all the files representing motifs.
3. Within "file_manipulation_new/src" and "file_manipulation/mnp_lib",
  there are header and C files that belong to the SFMT randomization
  program (already developed). The rest of the files were created by me.
4. Doxygen documentation can be found in "file_manipulation/doc/html/index.html".
