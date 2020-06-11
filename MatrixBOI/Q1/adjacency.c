/*Author: Prometheus*/
/*Date: 10.5.2020*/
/*Maman 12 Question 1*/

#include "adj.h"

bool path(adjmat A, int v, int u)
{
	bool result = FALSE; 
	
	/*if out of bounds*/ 
	if((u > N-1) || (v > N-1) || (v < 0) || (u < 0))
		result = FALSE;
	
	/*if nodes are connected or if path is to itself*/
	if(A[v][u] == 1 || u == v)
		result = TRUE;
	
	else
	{	/*go from each father to possible son*/
		for(int i = 0; i < N; i++)
		{	
			if(A[i][u] == 1)
				/*check if father is son of node to check*/
				result = path(A,v,i);
		}
	}
	
	return result;
}

void printADJ(adjmat A)
{
	/*print row print each column*/
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			printf("%d\t", A[i][j]);
		}
		printf("\n");

	}
}

void getADJ(adjmat A)
{
	/*for each row get each column value*/
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			printf("Enter value in place [%d][%d]: ", i, j);
			scanf("%d", &A[i][j]);
		}
		printf("\n");

	}
}

int main()
{
	adjmat A;
	int i,j;
	/*Add values to matrix and display the matrix on screen*/
	printf("Please input 1 to represent a father-son connection between [i] and [j] or 0 if it does not exist");
	getADJ(A);
	printADJ(A);
	

	while(getchar() != EOF)
	{
		/*get nodes to check*/
		printf("\nEnter First Node: ");
		scanf("%d", &i);
		printf("\nEnter Second Node: ");
		scanf("%d", &j);

		/*check if user wants to quit*/
		if(i == -1 && j == -1)
			break;
		
		/*check if a path exists*/
		if(path(A,i,j) == TRUE)
			printf("\nA path exists between %d and %d\n",i,j);

		else
			printf("\nA path does not exist between %d and %d\n",i,j);

		printf("\nTo exit reach EOF or use value -1 for i and j\n");
	}
	
	return 0;
}

