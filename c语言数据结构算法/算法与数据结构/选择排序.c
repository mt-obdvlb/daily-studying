//#define  _CRT_SECURE_NO_WARNINGS
//#include "
// "
//
//void selection_sort(int* data,int l,int r);
//
//int main() {
//	int* arr = getRandData(SMALL_N);
//	TEST(selection_sort, arr, SMALL_N);
//	free(arr);
//	return 0;
//}
//
//void selection_sort(int* data, int l,int r) {
//	for (int i = l; i < r - 1; i++) {
//		int ind = i;
//		for (int j = i + 1; j < r; j++) {
//			if (data[ind] cmp data[j]) {
//				ind = j;
//			}
//		}
//		swap(data[ind], data[i]);
//	}
//}