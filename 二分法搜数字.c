//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int binary_search(int arr[], int sz, int k);
//int main() {
//	int arr[]={  1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 7;
//	int ret = binary_search(arr, sz, k);
//	if (ret == -1) {
//		printf("û�ҵ�\n");
//	}
//	else
//	{
//		printf("�ҵ�����:%d", ret);
//	}
//	return 0;
//}
//
//int binary_search(int arr[], int sz, int k) {
//	int left = 0;
//	int right = sz - 1;
//	int mid = 0;
//	while (left<=right) {
//		mid = left + (right - left) / 2;
//		if (k <arr[mid]) {
//			right = mid - 1;
//		}
//		else if (k > arr[mid]) {
//				left = mid + 1;
//		}
//			else {
//				return mid;
//		}
//	}
//	return -1;
//}