#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int i = 0;
	int count = 0;
	int high = 0;
	int arr[10] = { 0 };
	for (i = 0; i < 10; i++) {
		scanf(" %d", &arr[i]);
	}
	scanf(" %d", &high);
	for (i = 0; i < 10; i++) {
		if (high + 30 >= arr[i]) {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}