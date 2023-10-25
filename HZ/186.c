//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int fac(int n , int* p,int i);
//
//int main1() {
//	int n = 0;
//	scanf("%d", &n);
//	int* p = (int*)malloc(n*sizeof(int));
//	int i = 0;
//	for (i = 0; i < n; i++) {
//		scanf("%d", p+i);
//	}
//	int count = 0;
//	i = 0;
//	count = fac(n,p,i);
//	printf("%d", count);
//	free(p);
//	p = NULL;
//	return 0;
//}
//
//int fac(int n, int* p,int i) {
//	if (i >= n){
//		return 0;
//	}
//	else {
//		return fac(n,p, i+ p[i])+1;
//	}
//}
