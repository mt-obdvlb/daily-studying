//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//typedef struct Vector {
//	int size, * date;
//}Vector;
//typedef struct Queue{
//	Vector* date;
//	int count, head, tail;
//}Queue;
//
//
//
//Queue* initQueue(int n);
//int push(int val, Queue* q);
//int pop(Queue* q);
//int front(Queue* q);
//int is_emety(Queue* q);
//void clearQueue(Queue* q);
//Vector* initVector(int n);
//void insertVector(Vector* v, int pos, int val);
//void clearVector(Vector* v);
//int seekVector(Vector* v,int pos);
//void output_Queue(Queue* v);
//void output_Vector(Vector* v,int pos);
//
//int main() {
//	srand((unsigned int)time(NULL));
//	#define MAX_OP 8
//	Queue* q = initQueue(MAX_OP);
//	for (int i = 0; i < MAX_OP; i++) {
//		int val = rand()%100;
//		int op = rand()%5;
//		switch (op) {
//			case 0:
//			case 1:
//				printf("pop\n");
//				pop(q);
//				output_Queue(q);
//				break;
//			case 2:
//			case 3:
//			case 4:
//				printf("push %d at %d\n",val,q->tail);
//				push(val, q);
//				output_Queue(q);
//				break;
//		}
//	}
//	clearQueue(q);
//	return 0;
//}
//
//Queue* initQueue(int n) {
//	Queue* q = (Queue*)malloc(sizeof(Queue));
//	q->date = initVector(n);
//	q->count = 0;
//	q->head = 0;
//	q->tail = 0;
//	return q;
//}
//
//void clearQueue(Queue* q) {
//	clearVector(q->date);
//	free(q);
//}
//
//int is_emety(Queue* q) {
//	return (q->count == 0);
//}
//
//int front(Queue* q) {
//	return (seekVector(q->date,q->head));
//}
//
//int push(int val, Queue* q) {
//	if (q == NULL) {
//		return 1;
//	}
//	insertVector(q->date, q->tail, val);
//	q->tail++;
//	if (q->tail >= q->date->size) {
//		q->tail = 0;
//	}
//	q->count++;
//	return 0;
//}
//
//int pop(Queue* q) {
//	if (is_emety) {
//		return 1;
//	}
//	q->head++;
//	q->count--;
//	return 0;
//}
//
//int seekVector(Vector* v,int pos) {
//	return v->date[pos];
//}
//
//Vector* initVector(int n) {
//	Vector* v = (Vector*)malloc(sizeof(Vector));
//	v->size = n;
//	v->date = (int*)malloc(sizeof(int) * n);
//	return v;
//}
//
//void clearVector(Vector* v) {
//	free(v->date);
//	free(v);
//}
//
//void insertVector(Vector* v, int pos, int val) {
//	v->date[pos] = val;
//}
//
//void output_Queue(Queue* v) {
//	for (int i = 0; i < v->count; i++) {
//		output_Vector(v->date, i);
//	}
//	printf("\n");
//}
//
//void output_Vector(Vector* v, int pos) {
//	printf("%d ", v->date[pos]);
//}