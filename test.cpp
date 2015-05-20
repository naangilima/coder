#include <iostream>
#include <stdio.h>
#define MAX 10000
int map[MAX][MAX];

using namespace std;

void dfs(int (*map)[MAX], int N)
{
	int i,j;
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

	int TC,T,N;
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
	
		dfs(map,N);
	}


	return 0;
}
