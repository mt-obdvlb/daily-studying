//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<string.h>
//#include<stdbool.h>
//
//
//#define OP_MAX 10000000
//#define TEST(func,arr,n) {\
//	printf("%s ",#func);\
//	int* copy = (int*)malloc(sizeof(arr)*n);\
//	memcpy(copy,arr,sizeof(int)*n);\
//	long long b = clock();\
//	func(copy,n);\
//	long long e = clock();\
//	printf("%lld\n",1000*(e - b)/CLOCKS_PER_SEC);\
//	free(copy);\
//}
//
//#define swap(a, b) {\
//	int __c = (a);\
//	(a) = (b), (b) = __c;\
//}
//
//#define FATHER(i) ((i)/2)
//#define LEFT(i) ( 2 * (i))
//#define RIGHT(i) (2*(i) + 1)
//#define cmp >
//
//int* getRandData(int n);
//bool check(int* arr, int n);
//void normal_heap(int* arr, int n);
//void linear_heap(int* arr, int n);
//inline void normal_heap_build(int* arr, int n);
//inline void linear_heap_build(int* arr, int n);
//inline void heap_sort_final(int* data, int n);
//inline void up_update(int* data, int i);
//inline void down_update(int* data, int i ,int n);
//
//int main() {
//	srand((unsigned int)time(NULL));
//	int* arr = getRandData(OP_MAX);
//	TEST(normal_heap, arr, OP_MAX);
//	TEST(linear_heap, arr, OP_MAX);
//	return 0;
//}
//
//void normal_heap(int* arr, int n) {
//	int* data = arr - 1;
//	normal_heap_build(data, n);
//	heap_sort_final(data, n);
//}
//
//void linear_heap(int* arr, int n) {
//	int* data = arr - 1;
//	linear_heap_build(data, n);
//	heap_sort_final(data, n);
//}
//
//int* getRandData(int n) {
//	int* arr = (int*)malloc(sizeof(int) * n);
//	int i = 0;
//	for (i = 0; i < n; i++) {
//		arr[i] = rand() % 100000;
//	}
//	return arr;
//}
//
//inline void normal_heap_build(int* arr, int n){
//	for (int i = 2; i <= n; i++) {
//		up_update(arr, i);
//	}
//}
//
//inline void linear_heap_build(int* arr, int n) {
//	for (int i = n / 2; i >= 1; i--) {
//		down_update(arr, i,n);
//	}
//}
//
//inline void up_update(int* data, int i) {
//	while (data[i] cmp data[FATHER(i)]&& i >1) {
//		swap(data[i],data[FATHER(i)]);
//		i = FATHER(i);
//	}
//}
//
//inline void down_update(int* data, int i, int n) {
//	while (LEFT(i) <= n) {
//		int ind = i,l = LEFT(i), r = RIGHT(i);
//		if (data[l] cmp data[ind]) {
//			ind = l;
//		}
//		if (r <= n && data[r] cmp data[ind]) {
//			ind = r;
//		}
//		if (ind == i) {
//			break;
//		}
//		swap(data[ind], data[i]);
//		i = ind;
//	}
//}
//
//bool check(int* arr, int n) {
//	int i = 1;
//	for (i = 1; i < n; i++) {
//		if (arr[i] < arr[i - 1]) {
//			return false;
//		}
//	}
//	return true;
//}
//
//inline void heap_sort_final(int* data, int n) {
//	for(int i = n;i>= 2;i--){
//		swap(data[1], data[i]);
//		down_update(data, 1,i - 1);
//	}
//}