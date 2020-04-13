/*
���������� ���� ���-13��
������������ ������ 2. �����

���������: ����� ���������� ��������� �� ���� ����� ����� �� �����,
������� ����� ������������ ���� ��� �����.

��������: ����� � ����������� ������ ���������� S �� �����
����� ������ ���� ������ �� ����, ���� � ������������� S ������
��� �� �����, ��� � �� �����, ������� ��� ���������.

��������� ������ ���� � ������� ���������.
� ������� ��������� �������� ������� ����� ���������� �����
��� ������� ���� � ������� ����, ��� �������� ����� ����������.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include "graph.h"
int main() {
	setlocale(LC_ALL, "RUS");
	int adj_mat[MAX_SIZE][MAX_SIZE];
	int min_i;
	int n, k;

	if (Input_graph (adj_mat, &n, &k) == 1)
	{
		printf ("������������ ����\n");
		system ("pause");
		return 0;
	}

	Print_graph (adj_mat, n);

	min_i = Get_min_sum_i (adj_mat, n);
	
	printf ("����� ������� ���� ����� - ��� �%d\n", min_i+1);

	system("pause");
	return 0;
}
