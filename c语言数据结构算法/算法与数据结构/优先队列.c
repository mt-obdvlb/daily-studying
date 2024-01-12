//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//#define ROOT 1
//#define cmp >
//#define FATHER(n) (n/2)
//#define LEFT(n) (2*n)
//#define RIGHT(n) (2*n+1)
//
//typedef struct PriorityQueue {
//	int* data,*__data;
//	int size, n;
//}PriorityQueue;
//
//PriorityQueue* initPQ(int size);
//void clear(PriorityQueue* p);
//int push(PriorityQueue* p, int val);
//int pop(PriorityQueue* p);
//int emety(PriorityQueue* p);
//int full(PriorityQueue* p);
//void up_updata(int* data,int n);
//void down_updata(int* data, int n,int i);
//void swap(int* a, int* b);
//void output(PriorityQueue* p);
//int top(PriorityQueue* p);
//
//int main() {
//	int op, x;
//#define MAX_OP 100
//	PriorityQueue* p = initPQ(MAX_OP);
//	while (~scanf("%d", &op)) {
//		if (op == 1) {
//			scanf("%d", &x);
//			printf("insert %d to priority_queue : \n", x);
//			push(p, x); // push
//			output(p);
//		}
//		else {
//			printf("pop : %d\n", top(p));
//			pop(p);     // pop
//			output(p);
//		}
//	}
//	clear(p);
//	return 0;
//}
//
//PriorityQueue* initPQ(int size){
//	PriorityQueue* p = (PriorityQueue*)malloc(sizeof(PriorityQueue));
//	p->__data = (int*)malloc(sizeof(int) * size);
//	p->data = p->__data - 1;
//	p->size = size;
//	p->n = 0;
//	return p;
//}
//
//void clear(PriorityQueue* p) {
//	if (!p) {
//		return;
//	}
//	free(p->__data);
//	free(p);
//}
//
//int emety(PriorityQueue* p) {
//	return p->n == 0;
//}
//
//int full(PriorityQueue* p) {
//	return p->n == p->size;
//}
//
//int push(PriorityQueue* p, int val) {
//	if (full(p)) {
//		return 0;
//	}
//	p->n++;
//	p->data[p->n] = val;
//	up_updata(p->data, p->n);
//	return 1;
//}
//
//int pop(PriorityQueue* p) {
//	if (emety(p)) {
//		return 0;
//	}
//	p->data[ROOT] = p->data[p->n];
//	p->n--;
//	down_updata(p->data, p->n, ROOT);
//	return 1;
//}
//
//void up_updata(int* data, int n)
// {
//	while (n > ROOT && data[n] cmp data[FATHER(n)]) {																
//		swap(&data[n], &data[FATHER(n)]);
//		n = FATHER(n);
//	}
//}
//
//void swap(int* a, int* b) {
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void down_updata(int* data,int n ,int i) {
//	while (LEFT(i) <= n) {
//		int ind = i ,l =LEFT(i),r = RIGHT(i);
//		if (data[l] cmp data[ind]) {
//			ind = l;
//		}
//		if (r <= n && data[r] cmp data[ind]) {
//			ind = r;
//		}
//		if (ind == i) {
//			break;
//		}
//		swap(&data[i], &data[ind]);
//		i = ind;
//	}
//}
//
//void output(PriorityQueue* p) {
//	printf("PQ(%d) : ", p->n);
//	for (int i = 1; i <= p->n; i++) {
//		printf("%d ", p->data[i]);
//	}
//	printf("\n");
//	return;
//}
//
//int top(PriorityQueue* p) {
//	return p->data[p->n];
//}