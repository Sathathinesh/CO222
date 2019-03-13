// Factorial.c
// Program to compute n!
// 2 versions are provided: iterative and recursive
#include <stdio.h>

int factorial_iter1(int);
int factorial_iter2(int);
int factorial(int);

int main(void) {
	int input;

	printf("Enter a non-negative integer: ");
	scanf("%d", &input);

	printf("Iterative version 1: %d! = %d\n", input, factorial_iter1(input));
	printf("Iterative version 2: %d! = %d\n", input, factorial_iter2(input));
	printf("Recursive version  : %d! = %d\n", input, factorial(input));

	return 0;
}

// Compute n!
// Iterative version 1
// Pre-cond: n >= 0
int factorial_iter1(int n) {
	int ans = 1, i;

	for (i=2; i<=n; i++)
		ans *= i;

	return ans;
}

// Compute n!
// Iterative version 2
// Pre-cond: n >= 0
int factorial_iter2(int n) {
	int ans = 1;

	while (n > 1) {
		ans *= n;
		n--;
	}

	return ans;
}

// Compute n!
// Recursive version
// Pre-cond: n >= 0
int factorial(int n) {
	if (n == 0)
		return 1;
	else
		return n * factorial(n-1);
}

