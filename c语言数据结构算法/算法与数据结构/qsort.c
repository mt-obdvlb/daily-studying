//#include "TEST1.h"
//
//int compare(const void* a, const void* b);
//
//int main() {
//	int* arr = getRandData(SMALL_N);
//	qsort(arr, SMALL_N, sizeof(int), compare);
//	if (check(arr,0,SMALL_N)) {
//		printf("OK");
//	}
//	else {
//		printf("NO");
//	}
//	free(arr);
//	return 0;
//}
//
//int compare(const void* a, const void* b) {
//	return (*(int*)a - *(int*)b);
//}