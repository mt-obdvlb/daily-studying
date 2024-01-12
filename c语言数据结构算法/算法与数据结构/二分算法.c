//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//#define min(a,b) ((a)<(b)?a:b)
//
//
//void test_binary_search(int n);
//void output(int* arr, int n, int target);
//int binary_search(int* arr, int n, int target);
//
//
//int main() {
//	srand((unsigned int)time(NULL));
//	#define N 10
//	test_binary_search(N);
//	return 0;
//}
//
//void test_binary_search(int n) {
//	int* arr = (int*)malloc(sizeof(int) * n);
//	arr[0] = rand() % 10;
//	for (int i = 1; i < n; i++) {
//		arr[i] = arr[i - 1] + rand() % 10;
//	}
//	int target = -1;
//	output(arr, n, -1);
//	while (~scanf("%d", &target)) {
//		output(arr, n, -1);
//		if (target < 0) {
//			break;
//		}
//		int ind = binary_search(arr, n, target);
//		output(arr, n, ind);
//	}
//	free(arr);
//}
//
//void output(int* arr, int n, int target) {
//	int len = 0;
//	for (int i = 0; i < n; i++) {
//		len+=printf("%4d", i);
//	}
//	printf("\n");
//	for (int i = 0; i < len; i++) {
//		printf("-");
//	}
//	printf("\n");
//	for (int i = 0; i < n; i++) {
//		if (i == target) printf("\033[1;32m");
//		printf("%4d", arr[i]);
//		if (i == target) printf("\033[0m");
//	}
//	printf("\n\n");
//}
//
//int binary_search(int* arr, int n, int target) {
//	int l = 0, r = n - 1, mid;
//	while (l <= r) {
//		mid = (l + r) / 2;
//		if (arr[mid] == target) {
//			return mid;
//		}
//		else if (arr[mid] > target) {
//			r = mid - 1;
//		}
//		else {
//			l = mid + 1;
//		}
//	}
//	return -1;
//}