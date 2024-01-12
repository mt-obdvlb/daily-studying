//#define  _CRT_SECURE_NO_WARNINGS
//#include"
// "
//
//void bubble_sort(int* arr, int l, int r);
//
//int main() {
//	int* arr = getRandData(SMALL_N);
//	TEST(bubble_sort, arr, SMALL_N);
//	free(arr);
//	return 0;
//}
//
//void bubble_sort(int* arr, int l, int r) {
//	for (int i = r - 1; i >= l + 1; i--) {
//		int count = 0;
//		for (int j = l; j < i; j++) {
//			if (arr[j] <= arr[j + 1]) {
//				continue;
//			}
//			swap(arr[j], arr[j + 1]);
//			count++;
//		}
//		if (count == 0) {
//			return;
//		}
//	}
//}