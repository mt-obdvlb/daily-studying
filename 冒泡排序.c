#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void bubble_sort(int arr[], int sz);
void swap(int* pa, int* pb);

int main() {
	int arr[]={ 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

void bubble_sort(int arr[], int sz) {
	int i = 0;
	for (i = 0; i < sz; i++) {
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				/*int tem = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tem;*/
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void swap(int* pa, int* pb) {
	int tem = *pa;
	*pa = *pb;
	*pb = tem;
}