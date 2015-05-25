#include <stdio.h>
#include <iostream>
#define MAX 100000
#define TRUE	1
#define FALSE	0

int  N = 0;
int  visited[MAX] = { 0, };
char map[10][10]  = { 0, };
char alpha[10];

void dfs(void)
{
	int i, j;

	for (i = 0; i < N; i++) {
		visited[i] = TRUE;
		printf("%c", alpha[i]);

		for (j = 0; j < N; j++)
		{
			if (visited[j] == FALSE && map[i][j] == FALSE)
			{
				map[i][j] = 1;
				printf("%c", alpha[j]);
				dfs();
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		visited[i] = 0;
	}

	printf("\n-------------\n");

}


void initialize(void)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		visited[i] = 0;
		alpha[i] = 0;
	}
	N = 0;
}

int main()
{

	int TC, T;
	int i,j;
	
	scanf_s("%d",&TC);
	T = TC;
	while (TC--)
	{	
		
		scanf_s("%s",&alpha); 
		
		printf("\n");
		for (j = 0; j < sizeof(alpha); j++)
		{
			if (alpha[j] == '\0'){
				break;
			}
			N++;
		}
		dfs();
		printf("Case #%d\n", T - TC);

		initialize();
		
		
	}
	
	return 0;
}