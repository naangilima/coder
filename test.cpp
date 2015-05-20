//http://hns17.tistory.com/entry/%EC%BD%94%EB%94%A9Recursive-Backtracking
#include <iostream>
#include <stdio.h>
#define MAX 10000
#define WALL  1
#define JEWEL 2
#define TRUE  1 
#define FALSE 0
int map[MAX][MAX];
int visited[MAX][MAX];
int N;
using namespace std;

void dfs(int start)
{
	int i,j;


	
	if(map[start][i] != WALL && visited[start][i] == FALSE)
	{
				
	}

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d ",map[i][j]);

		}
		printf("\n");
	}
	
}

int main()
{

	int TC,T;
	int i,j;

	scanf("%d",&TC);
	while(TC--)
	{
		scanf("%d",&N);

		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}	

		visited[0][0] = 1;
		dfs(0);
	}


	return 0;
}
