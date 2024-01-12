//#define  _CRT_SECURE_NO_WARNINGS
//#include "TEST1.h"
//
//void merge_sort(int* arr, int l, int r);
//
//int main() {
//	int* arr = getRandData(SMALL_N);
//	int* arr_ = getRandData(LARGE_N);
//	TEST(merge_sort, arr, SMALL_N);
//	TEST(merge_sort, arr_, LARGE_N);
//	free(arr);
//	free(arr_);
//	return 0;
//}
//
//void merge_sort(int* arr, int l, int r) {
//	if (r - l <= 1) {
//		return;
//	}
//	int mid = (l + r) / 2;
//	merge_sort(arr, l, mid);
//	merge_sort(arr, mid, r);
//	int* temp = (int*)malloc(sizeof(int) * (r - l));
//	int pa = l, pb = mid,k = 0;
//	while (pa < mid || pb < r) {
//		if (pb >= r || (pa < mid && arr[pa] < arr[pb])) {
//			temp[k++] = arr[pa++];
//		}
//		else {
//			temp[k++] = arr[pb++];
//		}
//	}
//	for (int i = l; i < r; i++) {
//		arr[i] = temp[i - l];
//	}
//}