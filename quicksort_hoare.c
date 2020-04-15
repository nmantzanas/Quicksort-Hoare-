#include <stdio.h>

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int HoarePartition(int A[], int l, int r) {
	
	int x = A[r];
	int i = l - 1;
	int j = r + 1;

	while (1) {
		
		do {
			j--;
		} while (A[j] > x);

		do {
			i++;
		} while (A[i] < x);

		if (i < j)
		{
			swap(&A[i], &A[j]);	
		}
		else {
			return i;
		}
		
	}
}

void Quicksort (int A[], int l, int r) {
	
	if (l < r) {
		int m = HoarePartition(A, l, r);
		Quicksort(A, l, m-1);
		Quicksort(A, m, r);
	}
}

void PrintArray(int A[], int size) {
	int i;

	for(i=0; i < size; i++) {
		printf("%d, ", A[i]);
	}
}

