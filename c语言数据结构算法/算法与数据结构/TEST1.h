#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

#define SMALL_N 5000
#define LARGE_N 10000000
#define TEST(func,arr,n) {\
	int* tmp = (int*)malloc(sizeof(arr)*n);\
	memcpy(tmp, arr,sizeof(int)*n);\
	long long b = clock();\
	func(tmp,0,n);\
	long long e = clock();\
	if(check(tmp,0,n))printf("YES\n");\
	else printf("NO\n");\
	printf("%lld ms\n",1000*(e-b)/CLOCKS_PER_SEC);\
	free(tmp);\
}
#define cmp >
#define swap(a, b) {\
	int __c = (a);\
	(a) = (b);\
	(b) = __c;\
}

bool check(int* data,int l, int r) {
	for (int i =l + 1; i < r; i++) {
		if (data[i -1] cmp data[i ]) {
			return false;
		}
	}
	return true;
}

int* getRandData(int n) {
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10000000;
	}
	return arr;
}