//#include "
// "
//
//void shell_sort(int* arr, int l, int r);
//void shell_sort_hibbard(int* arr, int l, int r);
//void unguarded_insert_sort(int* arr, int l, int r, int step);
//
//int main() {
//	int* arr = getRandData(SMALL_N);
//	TEST( shell_sort,arr, LARGE_N);
//	TEST(shell_sort_hibbard, arr, LARGE_N);
//	free(arr);
//	return 0;
//}
//
//void shell_sort(int* arr, int l, int r) {
//	int step = 1, k = 2, n = r - l;
//	do {
//		step = n / k == 0? 1: n/k;
//		for (int i = l; i < l + step; i++) {
//			unguarded_insert_sort(arr, i, r, step);
//		}
//		k = k*k;
//	} while (step!=1);
//}
//
//void shell_sort_hibbard(int* arr, int l, int r) {
//	int step = 1, k = 1, n = r - l;
//	while (step * 2 + 1 <= n / 2) {
//		step = step * 2 + 1;
//	}
//	while (step >= 1) {
//		for (int i = l; i < l + step; i++) {
//			unguarded_insert_sort(arr, i, r, step);
//		}
//		step /= 2;
//	}
//}
//
//void unguarded_insert_sort(int* arr, int l, int r, int step) {
//	int ind = l;
//	for (int i = l + step; i < r; i += step) {
//		if (arr[ind ] cmp arr[i]) {
//			ind = i;
//		}
//	}
//	while (ind > l) {
//		swap(arr[ind], arr[ind - step]);
//		ind -=step;
//	}
//	for (int i = l + step * 2; i < r; i += step) {
//		int j = i;
//		while (arr[j - step] cmp arr[j]) {
//			swap(arr[j], arr[j - step]);
//			j--;
//		}
//	}
//}