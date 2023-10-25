//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>	
//
//int arr[10] = { 0 };
//int f(int i, int j, int n);
//void print(int n);
//
//int main2() {
//	int n = 0;
//	scanf("%d", &n);
//	f(0, 1, n); 
//	return 0;
//}
//
//int f(int i, int j, int n) {
//	if (j > n) {
//		return 0;
//	}
//	int k = 0;
//	for (k = j; k <= n; k++) {
//		arr[i] = k;
//		print(i);
//		f(i + 1, k + 1, n);
//	}
//	return 0;
//}
//
//void print(int n) {
//	int i = 0;
//	for (i = 0; i <= n; i++) {
//		if (i == n) {
//			printf("%d", arr[i]);
//		}
//		else {
//			printf("%d ", arr[i]);
//		}
//	}
//	printf("\n");
//}
//
//
