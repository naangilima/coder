#include <stdio.h>
#include <iostream>
typedef struct _Employee {
	int order;
	int value;
	int grade;
}Employee;

#define MAX			300000
Employee map[MAX] = {0,};

void sort(int N)
{
	int i,j,k;
	int count = 0;
	Employee temp;

	for (i = 0; i < N-1; i++)
	{
		for (j = i+1; j < N; j++)
		{
			if (map[i].value < map[j].value)
			{
				temp = map[i];
				map[i] = map[j];
				map[j]= temp;
			}
		}
	 } //END SORT

	for (k = 0; k < N; k++)
	{
		if (k != 0 && map[k].value == map[k - 1].value)
		{
			map[k].grade = map[k - 1].grade;
			++count;
		}
		else 
		{
			map[k].grade = ++count;
		}
	}

}

void grader(int N)
{
	int i, j, k;
	Employee temp;

	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (map[i].order > map[j].order)
			{
				temp = map[i];
				map[i] = map[j];
				map[j] = temp;
			}
		}
	} //END SORT


	for (k = 0; k < N; k++)
	{
		printf("%d ", map[k].grade);
	}
	printf("\n");

}

int main()
{

	int TC, T;
	int N;
	int i;
	
	scanf_s("%d",&TC);
	T = TC;
	while (TC--)
	{
		scanf_s("%d",&N);
		
		for (i = 0; i < N; i++)
		{
			// scan order & value
			map[i].order = i;			 
			scanf_s("%d",&map[i].value); 
		}

		sort(N);
		printf("Case #%d\n", T - TC);
		grader(N);

		
	}
	
	return 0;
}