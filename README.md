# Clusters
Analysis of sparse and dense graphs

Looking for "clusters" (groups of vertices with a lot of edges between them) in any given graph, returning an output file describing
the best partition of the graph to groups (according to a given modularity formula). The code works very efficiently, both in time
complexity (using mathematical calculations, avoiding expensive operations) and in space complexity.
Basically, the code reads a binary file representing the graph (vertices and edges), saves it in a much more efficient data structure, a 
"sparse matrix", then randomizes an initial vector in the fitting size, using the known Power-Iteration (specially made for sparse matrices)
in order to find the leading eigenvalue and vector (after a matrix shifting, making sure it's positive). Finally, another modularity maximization
method is activated, in order to move every vertex in to his optimal group. 

About the code:

Since the project should run on Linux, and a makefile is necessary, almost every function is written in a different file. This way of
coding has two big advantages: 
1. Having a bug, this style makes it easier to find the defected function.
2. There is no need to compile and link big parts of the project after every little change, the makefile will choose only the changed files.
