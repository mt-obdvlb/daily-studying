#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


void Swap(int* px, int* py);
int main() {
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("交换前的数字a=%d , b=%d", a, b);
	Swap(&a,&b);
	printf("交换后的数字a=%d , b=%d", a, b);
	return 0;
}

void Swap(int* px, int* py) {
	int z = *px;
	*px = *py;
	*py = z;
}