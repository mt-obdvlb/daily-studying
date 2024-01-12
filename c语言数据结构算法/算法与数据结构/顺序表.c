//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define MAX_OP 20
//
//typedef struct vector {
//	int count;
//	int size;
//	int* date;
//}vector;
//
//vector* getNewVector(int n);
//int clear(vector* v);
//int insert(vector* v, int pos, int val);
//int erase(vector* v, int pos);
//void output_vector(vector* v);
//
//int main() {
//	srand((unsigned int)time(NULL));
//	vector* v = getNewVector(MAX_OP);
//	int i = 0;
//	for (i = 0; i < MAX_OP; i++) {
//		int op = rand() % 4;
//		int pos=0, val=0,ret = 0;
//		switch (op) {
//		case 0:
//		case 1:
//		case 2:
//			pos = rand() % (v->count + 2);
//			val = rand() % 100;
//			ret = insert(v, pos, val);
//			printf("insert %d at %d to vector = %d\n", val, pos,ret );
//			break;
//		case 3:
//			pos = rand() % (v->count + 2);
//			ret = erase(v, pos);
//			printf("erase %d vector = %d\n", pos, ret);
//			break;
//		}
//		output_vector(v);
//	}
//	clear(v);
//	return 0;
//}
//
//vector* getNewVector(int n) {
//	vector* p = (vector*)malloc(sizeof(vector));
//	p->count = 0;
//	p->size = n;
//	p->date = (int*)malloc(sizeof(int) * n);
//	return p;
//}
//
//int clear(vector* v) {
//	if (v == NULL) {
//		return 0;
//	}
//	free(v->date);
//	free(v);
//	return 0;
//}
//
//int insert(vector* v, int pos, int val) {
//	if (v->size == v->count||pos<0||pos > v -> count) {
//		return 1;
//	}
//	int i = 0;
//	for (i = v->count - 1; i >= pos; i--) {
//		v->date[i + 1] = v->date[i];
//	}
//	v->date[pos] = val;
//	v->count += 1;
//	return 0;
//}
//
//int erase(vector* v, int pos) {
//	if (pos < 0 || pos >= v->count) {
//		return 1;
//	}
//	int i = 0;
//	for (i = pos ; i < v->count; i++) {
//		v->date[i] = v->date[i + 1];
//	}
//	v->count -= 1;
//	return 0;
//}
//
//void output_vector(vector* v) {
//	int i = 0;
//	int len = 0;
//	for (i = 0; i < v->size; i++) {
//		len += printf("%-3d",i);
//	}
//	printf("\n");
//	for (i = 0; i < len; i++) {
//		printf("-");
//	}
//	printf("\n");
//	for (i = 0; i < v -> count; i++) {
//		printf("%-3d", v->date[i]);
//	}
//	printf("\n");
//}