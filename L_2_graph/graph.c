#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"

// Читает граф в матрицу смежности
int Input_graph (int arr[MAX_SIZE][MAX_SIZE], int *n, int *k)
{
	int i, j, a, b, d;
	if (scanf("%d%d", &(*n), &(*k)) != 2 || *n < 2 || *k < 1)
		return 1;

	for (i = 0; i < *n; i++)
	{
		for (j = 0; j < *n; j++)
		{
			arr[i][j] = 0;
		}
	}

	for (i = 0; i < *k; i++)
	{
		if (scanf("%d%d%d", &a, &b, &d) != 3 || a < 1 || b < 1 || d < 0)
		{
			return 1;
		}
		arr[a-1][b-1] = d;
		arr[b-1][a-1] = d;		
	}

	return 0;
}

// Выводит матрицу смежности
void Print_graph (int arr[][MAX_SIZE], int n)
{
	int i, j;
	printf ("\nВведенный граф:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf ("%d ", arr[i][j]);
		}
		printf ("\n");
	}
}

// Находит минимальную сумму расстояний от выбранного до остальных узлов
int Find_dist_dijkstra (int a[][MAX_SIZE], int n, int st) //st от нуля
{
	int i, j, min_dist = 0, min_s = 0;
	int dist[MAX_SIZE], used[MAX_SIZE];	
	int min_vertex = st;

	for (j = 0; j < n; j++)
	{
		dist[j] = INT_MAX;
		used[j] = 0;
	}
	dist[st] = 0;
	while (min_dist < INT_MAX)
	{
		i = min_vertex;
		used[i] = 1;

		for (int j = 0; j < n; j++)
		{
			if (a[i][j] && dist[i] + a[i][j] < dist[j])			
				dist[j] = dist[i] + a[i][j];			
		}
		min_dist = INT_MAX;
		for (int j = 0; j < n; j++)		
			if (!used[j] && dist[j] < min_dist)
			{
				min_dist = dist[j];
				min_vertex = j;
			}		
	}

	for (i = 0; i < n; i++)	
		min_s += dist[i];
	return min_s;
}

// Находит узел с минимальной суммой расстояний до остальных узлов
int Get_min_sum_i (int a[][MAX_SIZE], int n)
{
	int i, dist, min_i;
	int min_sum = INT_MAX;

	for (i = 0; i < n; i++)
	{
		dist = Find_dist_dijkstra (a, n, i);
		if (dist <= min_sum)
		{
			min_sum = dist;
			min_i = i;
		}
	}
	return min_i;
}
