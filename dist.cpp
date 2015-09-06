#include <iostream>
#include <stdio.h>

#define _x 1
#define _y 2

int inter[6][3][3];
int dist[6];
int visited[6] = {0,}; 
int INTER_CNT;
int result;

using namespace std;

int distance(int x1,int y1,int x2, int y2)
{
	int x,y;

	x = x1-x2;
	y = y1-y2;

	if(x<0) x = x*-1;
	if(y<0) y = y*-1;

	return x+y;
	
}

void search(int start, int point ,int length)  
{

	int i,j;

	visited[start] = 1;

	if(start !=0 && point == 1) {
		point = 2;
	} else if(start !=0 && point == 2) {
		point = 1;
	}

	
	for(i=1; i<=INTER_CNT; i++)
	{
		printf("\nvisited[%d]: %d\n",i,visited[i]);
		if(visited[i] =! 1)
		{
			for(j=1;j<=2;j++)
			{
				printf("\n -- %d => %d",i,j);
				length = length + distance(inter[start][point][_x],inter[start][point][_y],inter[i][j][_x],inter[i][j][_y]) + dist[i];
				if(length>result) {
					j = 2;
				} else {
					search(i,j,length);
				}
			}	
		}
		
	}
				
	length = length + distance(inter[start][point][_x],inter[start][point][_y],inter[0][2][_x],inter[0][2][_y]);

	if(length < result) {
		result=length;
	}
}

int main()
{

	int TC,T;
	int i,j,k;

	scanf("%d",&TC);
	T = TC;
	while(TC--)
	{

		cin >> INTER_CNT;
		result = 0;

		for(i=1; i<=2; i++) 
		{
			for(j=1; j<=2; j++) 
			{
				cin >> inter[0][i][j];
			}
		}

		
		result = distance(inter[0][1][_x],inter[0][1][_y],inter[0][2][_x],inter[0][2][_y]);
		

		for(k=1;k<=INTER_CNT; k++) {
			for(i=1; i<=2; i++) 
			{
				for(j=1; j<=2; j++) 
				{
					cin>>inter[k][i][j];
				}
			}
			cin>>dist[k];
		}


		printf("%d",0);
		search(0,1,0);

		cout<<"#"<<T-TC<<" "<<result<<endl;

	}

	return 0;
}
