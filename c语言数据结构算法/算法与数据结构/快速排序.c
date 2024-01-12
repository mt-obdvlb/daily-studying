//#include "TEST1.h"
//
//void quick_sort(int* arr, int l, int r);
//void super_quick_sort(int* arr, int l, int r);
//void super_super_quick_sort(int* arr, int l, int r);
//void super_super_super_quick_sort(int* arr, int l, int r);
//void __super_super_super_super_quick_sort(int* arr, int l, int r);
//void super_super_super_super_quick_sort(int* arr, int l, int r);
//int three_point_select(int a, int b, int c);
//void unguarded_insert_sort(int* arr, int l, int r);
//
//int main() {
//	int* arr = getRandData(LARGE_N);
//	TEST(quick_sort, arr, LARGE_N);
//	TEST(super_quick_sort, arr, LARGE_N);
//	TEST(super_super_quick_sort, arr, LARGE_N);
//	TEST(super_super_super_quick_sort, arr, LARGE_N);
//	TEST(super_super_super_super_quick_sort, arr, LARGE_N);
//	free(arr);
//	return 0;
//}
//
//void quick_sort(int* arr, int l, int r) {
//	int n = r - l;
//	if (n <= 2) {
//		if (n <= 1) {
//			return;
//		}
//		if (arr[l] cmp arr[l + 1]) {
//			swap(arr[l], arr[l + 1]);	
//		}
//		return;
//	}
//	int x = l, y = r - 1, z = arr[x];
//	while (x < y) {
//		while (x < y && z <= arr[y]) {
//			y--;
//		}
//		if (x < y) {
//			arr[x++] = arr[y];
//		}
//		while (x < y && arr[x] <= z) {
//			x++;
//		}
//		if (x < y) {
//			arr[y--] = arr[x];
//		}
//	}
//	arr[x] = z;
//	quick_sort(arr, l, x);
//	quick_sort(arr, x + 1, r);
//}
//
//void super_quick_sort(int* arr, int l, int r) {
//	if (r - l <= 2) {
//		if (r - l <= 1) return;
//		if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
//		return;
//	}
//	int x = l, y = r - 1, z = arr[l];
//	do {
//		while (arr[x] < z) x++;
//		while (arr[y] > z) y--;
//		if (x <= y) {
//			swap(arr[x], arr[y]);
//			x++, y--;
//		}
//	} while (x <= y);
//	super_quick_sort(arr, l, y + 1);
//	super_quick_sort(arr, x, r);
//}
//
//void super_super_quick_sort(int* arr, int l, int r) {
//	if (r - l <= 2) {
//		if (r - l <= 1) return;
//		if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
//		return;
//	}
//	int x = l, y = r - 1;
//	int z = three_point_select(
//		arr[l],
//		arr[r - 1],
//		arr[(l + r) / 2]
//	);
//	do {
//		while (arr[x] < z) x++;
//		while (arr[y] > z) y--;
//		if (x <= y) {
//			swap(arr[x], arr[y]);
//			x++, y--;
//		}
//	} while (x <= y);
//	super_super_quick_sort(arr, l, y + 1);
//	super_super_quick_sort(arr, x, r);
//}
//
//int three_point_select(int a, int b, int c) {
//	if (a > b) {
//		swap(a, b);
//	}
//	if (a > c) {
//		swap(a, c);
//	}
//	if (b > c) {
//		swap(b, c);
//	}
//	return b;
//}
//
//void super_super_super_quick_sort(int* arr, int l, int r) {
//	if (r - l <= 2) {
//		if (r - l <= 1) return;
//		if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
//		return;
//	}
//	while(l<r){
//		int x = l, y = r - 1;
//		int z = three_point_select(
//			arr[l],
//			arr[r - 1],
//			arr[(l + r) / 2]
//		);
//		do {
//			while (arr[x] < z) x++;
//			while (arr[y] > z) y--;
//			if (x <= y) {
//				swap(arr[x], arr[y]);
//				x++, y--;
//			}
//		} while (x <= y);
//		super_super_quick_sort(arr, l, y + 1);
//		l = x;
//	}
//}
//
//void __super_super_super_super_quick_sort(int* arr, int l, int r) {
//	if (r - l <= 2) {
//		if (r - l <= 1) return;
//		if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
//		return;
//	}
//	while (r - l< 16) {
//		int x = l, y = r - 1;
//		int z = three_point_select(
//			arr[l],
//			arr[r - 1],
//			arr[(l + r) / 2]
//		);
//		do {
//			while (arr[x] < z) x++;
//			while (arr[y] > z) y--;
//			if (x <= y) {
//				swap(arr[x], arr[y]);
//				x++, y--;
//			}
//		} while (x <= y);
//		super_super_quick_sort(arr, l, y + 1);
//		l = x;
//	}
//}
//
//void super_super_super_super_quick_sort(int* arr, int l, int r) {
//	__super_super_super_super_quick_sort(arr, l, r);
//	unguarded_insert_sort(arr, l, r);
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
//		swap(arr[ind], arr[ind - 1]);
//		ind--;
//	}
//
//	for (int i = l + 1; i < r; i++) {
//		int j = i;
//		while (arr[j - 1] cmp arr[j]) {
//			swap(arr[j], arr[j - 1]);
//			j--;
//		}
//	}
//}