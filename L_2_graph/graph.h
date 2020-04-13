#ifndef GRAPH_H
#define _CRT_SECURE_NO_WARNINGS
#define GRAPH_H
#include <stdio.h>
#define MAX_SIZE 200
#define INT_MAX 2147483647

// ������ ���� � ������� ���������
int Input_graph (int a[MAX_SIZE][MAX_SIZE], int *n, int *k);

// ������� ����������� ����� ���������� �� ���������� �� ��������� �����
int Find_dist_dijkstra (int a[][MAX_SIZE], int n, int st);

// ������� ���� � ����������� ������ ���������� �� ��������� �����
int Get_min_sum_i (int a[][MAX_SIZE], int n);

// ������� ������� ���������
void Print_graph (int adj_mat[][MAX_SIZE], int n);

#endif // !GRAPH_H