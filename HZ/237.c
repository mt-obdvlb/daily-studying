//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int arr[10] = { 0 };
//int vis[10] = {0};
//
//void print(int n);
//int f(int i, int n);
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	f(0, n);
//	return 0;
//}
//
//void print(int n) {
//	int i = 0;
//	for (i = 0; i < n; i++) {
//		if (i == n - 1) {
//			printf("%d", arr[i]);
//		}
//		else {
//			printf("%d ", arr[i]);
//		}
//	}
//	printf("\n");
//}
//int f(int i, int n) {
//	if (i == n) {
//		print(n);
//		return 0;
//	}
//	int k = 0;
//	for (k = 1;  k <= n; k++) {
//		if (vis[k] == 1) {
//			continue;
//		}
//		vis[k] = 1;
//		arr[i] = k;
//		f(i + 1, n);
//		vis[k] = 0;
//	}
//	return 0;
//}