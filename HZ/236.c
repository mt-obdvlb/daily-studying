//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int f(int i,int j,int n, int m);
//void print(int n);
//int arr[10] = { 0 };
//
//
//int main() {
//	int n = 0;
//	int m = 0;
//	scanf("%d%d", &m, &n);
//	f(0,1,n,m);
//	return 0;
//}
//
//int f(int i,int j,int n, int m) {
//	if (i == n) {
//		print(n);
//		return 0;
//	}
//	
//	{
//		int k = 0;
//		for (k = j; k <= m&&m-k>=n-i - 1; k++) {
//			
//			arr[i] = k;
//			f(i + 1, k + 1, n, m);
//		}
//	}
//	return 0;
//	
//}
//
//void print(int n) {
//	int i = 0;
//	for (i = 0; i < n; i++) {
//		if (i == n-1) {
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
