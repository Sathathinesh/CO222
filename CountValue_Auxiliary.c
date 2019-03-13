// CountValue_Auxiliary.c
// Count the number of times a certain value appears in an array.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 15

void initArray(int [], int);
void printArray(int [], int);
int countValue_iter(int, int [], int);
int countValue(int, int [], int);
int countValue_recur(int, int [], int, int);

int main(void) {
	int list[ARRAY_SIZE], value;

	initArray(list, ARRAY_SIZE);
	printArray(list, ARRAY_SIZE);

	printf("Enter search value: ");
	scanf("%d", &value);

	printf("Iterative: Number of times the value %d occurs = %d\n",
	       value, countValue_iter(value, list, ARRAY_SIZE));
	printf("Recursive: Number of times the value %d occurs = %d\n",
	       value, countValue(value, list, ARRAY_SIZE));

	return 0;
}

// Initialise array elements with random values
// in the range [-9, 9]
void initArray(int arr[], int size) {
	int i;

	srand(time(NULL));
	for (i=0; i<size; i++)
		arr[i] = rand()%19 - 9;
}

// Print values in array
void printArray(int arr[], int size) {
	int i;

	for (i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
// Count the number of times value appear in arr
// Iterative version
// Pre-cond: size >= 0
int countValue_iter(int value, int arr[], int size) {
	int count = 0, i;

	for (i=0; i<size; i++)
		if (value == arr[i])
			count++;
	
	return count;
}

// Driver function for countValue_recur()
// Pre-cond: size >= 0
int countValue(int value, int arr[], int size) {
	return countValue_recur(value, arr, 0, size);
}

// Count the number of times value appear in arr
// Recursive version
// Pre-cond: size >= 0
int countValue_recur(int value, int arr[], int start, int size) {
	if (start == size)
		return 0;
	else
		return (value == arr[start]) + 
		        countValue_recur(value, arr, start+1, size);
}

