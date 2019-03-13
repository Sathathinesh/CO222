// Fibonacci.c
// Program to compute fibonacci number.
// Fibonacci series: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
#include <stdio.h>

int fib_iter(int);
int fib(int);

int main(void) {
	int num;

	printf("Enter a non-negative integer: ");
	scanf("%d", &num);

	printf("The %d", num);
	if (num/10%10 != 1) {
		switch (num%10) {
			case 1: printf("st"); break;
			case 2: printf("nd"); break;
			case 3: printf("rd"); break;
			default: printf("th");
		}
	}
	else {
		printf("th");
	}
	printf(" fibonacci number is\n");
	printf("Iterative version: %d\n", fib_iter(num));
	printf("Recursive version: %d\n", fib(num));
	return 0;
}

// To compute the nth fibonacci number
// Iterative version
// Pre-cond: n >= 0
int fib_iter(int n) {
	int prev1 = 1, prev2 = 0, sum;

	if (n < 2)
		return n;

	for(; n>1; n--) {
		sum = prev1 + prev2; 
		prev2 = prev1;
		prev1 = sum;
	}
	return sum;
}

// To compute the nth fibonacci number
// Recursive version
// Pre-cond: n >= 0
int fib(int n) {
	if (n < 2)
		return n; 
	else 
		return fib(n-1) + fib(n-2);
}

