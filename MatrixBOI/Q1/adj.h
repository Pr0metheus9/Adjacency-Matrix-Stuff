/*header file for adjacency.c*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 11

/*define boolean type and N by N matrix for future use */
typedef enum {FALSE, TRUE} bool;
typedef bool adjmat[N][N];

/*function to find if a path exists between two nodes in the graph*/
bool path(adjmat A, int u, int v);
/*function to print matrix too screen*/
void printADJ(adjmat A);
/*function to get data for matrix*/
void getADJ(adjmat A);

