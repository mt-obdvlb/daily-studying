//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int arr[20] = { 0 };
//int vis[20] = { 0 };
//
//void output(int n);
//int fac(int n, int i);
//int is_legal(int n);
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	fac(n, 0);
//	return 0;
//}
//
//int fac(int n, int i) {
//	if (i == n) {
//		if (is_legal(n)) {
//			output(n);
//		}
//		return 0;
//	}
//	int j = 0;
//	for (j = 0; j < n; j++) {
//		if (vis[j]) {
//			continue;
//		}
//		arr[i] = j+1;
//		vis[j] = 1;
//		fac(n, i + 1);
//		vis[j] = 0;
//	}
//}
//
//void output(int n) {
//	int i = 0;
//	for (i = 0; i < n; i++) {
//		printf("%d", arr[i]);
//	}
//	printf("\n");
//}
//
//int is_legal(int n) {
//	int* nums = (int*)malloc(sizeof(int) * n);
//	int top = -1;
//	int x = 1;
//	for (int i = 0; i < n; i++) {
//		if (top == -1 || arr[i] > nums[top]) {
//			while (x <= arr[i]) {
//				nums[top + 1] = x;
//				x++;
//				top++;
//			}
//		}
//		if (top == -1 || arr[i] != nums[top]) {
//			return 0;
//		}
//		top--;
//	}
//	return 1;
//}