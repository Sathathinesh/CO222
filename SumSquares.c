// SumSquares.c
// Compute sum of squares.
#include <stdio.h>

void swap(int *, int *);
int sumSq1(int, int);
int sumSq2(int, int);
int sumSq3(int, int);

int main(void) {
	int num1, num2;

	printf("Enter 2 positive integers: ");
	scanf("%d %d", &num1, &num2);
	if (num1 > num2)
		swap(&num1, &num2);

	printf("sumSq1(%d, %d) = %d\n", num1, num2, sumSq1(num1, num2));
	printf("sumSq2(%d, %d) = %d\n", num1, num2, sumSq2(num1, num2));
	printf("sumSq3(%d, %d) = %d\n", num1, num2, sumSq3(num1, num2));
	return 0;
}

// Swap *n1 with *n2
void swap(int *n1, int *n2) {
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

// Compute the sum of squares
// x^2 + (x+1)^2 + ... + (y-1)^2 + y^2
// Precond: x <= y
int sumSq1(int x, int y) {
	if (x == y)
		return x * x;
	else 
		return x * x + sumSq1(x+1, y);
}

// Compute the sum of squares
// x^2 + (x+1)^2 + ... + (y-1)^2 + y^2
// Precond: x <= y
int sumSq2(int x, int y) {
	if (x == y)
		return y * y;
	else 
		return y * y + sumSq2(x, y-1);
}

// Compute the sum of squares
// x^2 + (x+1)^2 + ... + (y-1)^2 + y^2
// Precond: x <= y
int sumSq3(int x, int y) {
	int mid; // middle value

	if (x == y)
		return x * x;
	else {
		mid = (x + y)/2;
		return sumSq3(x, mid) + sumSq3(mid+1, y);
	}
}

