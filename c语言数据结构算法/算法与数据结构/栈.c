//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//typedef struct Stack {
//	int* date;
//	int top, size;
//}Stack;
//
//Stack* initStack(int n);
//int push(Stack* s, int val);
//int pop(Stack* s);
//int emety(Stack* s);
//void clearStack(Stack* s);
//void output_Stack(Stack* s);
//
//int main() {
//	srand((unsigned int)time(NULL));
//	int i = 0;
//	Stack* s = initStack(10);
//	for (i = 0; i < 10; i++) {
//		int val = rand()%100;
//		int op = rand()%3;
//		switch (op) {
//		case 0:
//		case 1:
//			printf("push\n");
//			push(s, val);
//			output_Stack(s);
//		case 2:
//			printf("pop\n");
//			pop(s);
//			output_Stack(s);
//		}
//	}
//	clearStack(s);
//	return 0;
//}
//
//Stack* initStack(int n) {
//	Stack* s = (Stack*)malloc(sizeof(Stack));
//	s->date = (int*)malloc(sizeof(int)*n);
//	s->size = n;
//	s->top = -1;
//	return s;
//}
//
//int push(Stack* s, int val) {
//	if (s->top + 1 == s->size) {
//		return 1;
//	}
//	s->date[s->top + 1] = val;
//	s->top++;
//	return 0;
//}
//
//int pop(Stack* s) {
//	if (emety(s)) {
//		return 1;
//	}
//	s->top--;
//	return 0;
//}
//
//int emety(Stack* s) {
//	return s->top == -1;
//}
//
//void clearStack(Stack* s) {
//	free(s->date);
//	free(s);
//}
//
//void output_Stack(Stack* s) {
//	int i = 0;
//	for (i = s->top; i >=0; i--) {
//		printf("%4d", s->date[i]);
//	}
//	printf("\n\n");
//}