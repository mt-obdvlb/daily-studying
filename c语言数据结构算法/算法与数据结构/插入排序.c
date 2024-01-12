//#define  _CRT_SECURE_NO_WARNINGS
//#include "
// "
//
//void insert_sort(int* arr, int l, int r);
//void unguarded_insert_sort(int* arr, int l, int r);
//
//
//int main() {
//	int* arr = getRandData(SMALL_N);
//	TEST(insert_sort,arr ,SMALL_N);
//	TEST(unguarded_insert_sort, arr, SMALL_N);
//	free(arr);
//	return 0;
//}
//
//void insert_sort(int* arr, int l, int r) {
//	for (int i = l + 1; i < r; i++) {
//		int j = i;
//		while (j > l && arr[j - 1] cmp arr[j]) {
//			swap(arr[j], arr[j - 1]);
//			j--;
//		}
//	}
//
//}
//
//void unguarded_insert_sort(int* arr, int l, int r) {
//	int ind = l;
//	for (int i = l + 1; i < r; i++) {
//		if (arr[ind] cmp arr[i]) {
//			ind = i;
//		}
//	}
//	while (ind > l) {
//		swap(arr[ind],arr[ind - 1]);
//		ind--;
//	}
//
//	for (int i = l + 1; i < r; i++) {
//		int j = i;
//		while ( arr[j - 1] cmp arr[j]) {
//			swap(arr[j], arr[j - 1]);
//			j--;
//		}
//	}
//}