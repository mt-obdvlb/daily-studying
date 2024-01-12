//#include "
// 
// "
//
//#define K 65536
//
//void radix_sort(int* arr, int l, int r);
//
//int main() {
//	int* arr = getRandData(SMALL_N);
//	int* arr_ = getRandData(LARGE_N);
//	TEST(radix_sort, arr, SMALL_N);
//	TEST(radix_sort, arr_,LARGE_N);
//	free(arr);
//	free(arr_);
//	return 0;
//}
//
//void radix_sort(int* arr, int l, int r) {
//	int* cot = (int*)malloc(sizeof(int) * K);
//	int* temp = (int*)malloc(sizeof(int) * (r - l));
//	memset(cot, 0, sizeof(int) * K);
//	for (int i = l; i < r; i++) {
//		cot[arr[i] % K]++;
//	}
//	for (int i = 1; i < K; i++) {
//		cot[i] += cot[i - 1];
//	}
//	for (int i = r - 1; i >= l; i--) {
//		temp[--cot[arr[i] % K]] = arr[i];
//	}
//	memcpy(arr, temp, sizeof(int) * (r - l));
//	memset(cot, 0, sizeof(int) * K);
//	for (int i = l; i < r; i++) {
//		cot[arr[i] / K]++;
//	}
//	for (int i = 1; i < K; i++) {
//		cot[i] += cot[i - 1];
//	}
//	for (int i = r - 1; i >= l; i--) {
//		temp[--cot[arr[i] / K]] = arr[i];
//	}
//	memcpy(arr, temp, sizeof(int) * (r - l));
//}