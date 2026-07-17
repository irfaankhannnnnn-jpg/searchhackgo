#include <stdio.h>
#include <string.h>


int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div(int a, int b) { return a / b; }


int main() {
	int(*ops[4])(int, int) = {add, sub, mul, div};
	char symbols[] = {'+', '-', '*', '/'};


	int a = 10, b = 3;
	for (int i = 0; i < 4; i++) {
	    printf("%d %c %d: %d\n", a, symbols[i], b, ops[i](a, b));
	}

	return 0;
}


