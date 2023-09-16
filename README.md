# Motif Analysis
The program requires the use of a Linux operating system.

## Set-up
1. Insert your path into the "project_path" variable
   located in MAIN.C: The path should be identical to the one
   you would use to access this folder from the terminal. The
   path should be preceded by 'cd'.

2. To run the program, type "MAKE RUN" in the terminal
   from the FILE_MANIPULATION_NEW folder
   (after compiling the MAKEFILE, also located in the same folder).

3. It is also necessary to compile all the MAKEFILEs
   in the MOTIFS_SIGNIFICANCE folder. More information
   can be found in the README files in the same folder.
   Specifically, consider the MAKEFILEs located in
   code_paper/examples/exact.

4. It is recommended to adjust the number of permutations
   if you want to reduce execution time, especially for large datasets.


## ADDITIONAL INFORMATION:
1. In the "motifs_significance/datasets" folder, you can find
  all the datasets that can be used with the program.
2. The results of the program for each type of motif are
  located in the "Result_Every_Motif" folder.
3. The "motifs_significance/code_paper/examples/motifs" folder
  contains all the files representing motifs.
4. Within "file_manipulation_new/src" and "file_manipulation/mnp_lib",
  there are header and C files that belong to the SFMT randomization
  program (already developed). The rest of the files were created by me.
5. Doxygen documentation can be found in "file_manipulation/doc/html/index.html".
