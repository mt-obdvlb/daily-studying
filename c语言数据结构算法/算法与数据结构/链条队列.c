//
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//
//typedef struct Node {
//	int date;
//	struct Node* next;
//}Node;
//
//typedef struct linkList {
//	Node head, * tail;
//}linkList;
//
//typedef struct Queue {
//	linkList* l;
//	int count;
//}Queue;
//
//Queue* initQueue(void);
//void push(Queue* q, int val);
//void clearQueue(Queue* q);
//int pop(Queue* q);
//int is_emetyQueue(Queue* q);
//int frontQueue(Queue* q);
//linkList* initLinkList();
//Node* getNewNode(int val);
//void clearLinkList(linkList* l);
//void clearNode(linkList* l);
//int frontLinkList(linkList* l);
//void insertLinkList(linkList* l, int val);
//void eraseLinkList(linkList* l);
//void output_Queue(Queue* q);
//int output_LinkList(linkList* l,int count);
//
//int main() {
//	srand((unsigned int)time(NULL));
//#define MAX_OP 8
//	Queue* q = initQueue();
//	for (int i = 0; i < MAX_OP; i++) {
//		int val = rand() % 100;
//		int op = rand() % 7;
//		switch (op) {
//		case 0:
//		case 1:
//			printf("pop\n");
//			pop(q);
//			output_Queue(q);
//			break;
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//		case 6:
//			printf("push %d \n", val);
//			push(q, val);
//			output_Queue(q);
//			break;
//		}
//	}
//	clearQueue(q);
//	return 0;
//}
//
//Queue* initQueue(void) {
//	Queue* q = (Queue*)malloc(sizeof(Queue));
//	q->l = initLinkList();
//	q->count = 0;
//	return q;
//}
//
//void clearQueue(Queue* q) {
//	if (q == NULL) {
//		return;
//	}
//	clearLinkList(q->l);
//	free(q);
//}
//
//int is_emetyQueue(Queue* q) {
//	return q->count == 0;
//}
//
//int frontQueue(Queue* q) {
//	return frontLinkList(q->l);
//}
//
//int pop(Queue* q) {
//	if (q->count == 0) {
//		return 1;
//	}
//	eraseLinkList(q->l);
//	q->count--;
//	return 0;
//}
//
//void push(Queue* q, int val) {
//	insertLinkList(q->l, val);
//	q->count++;
//	
//}
//
//linkList* initLinkList() {
//	linkList* l = (linkList*)malloc(sizeof(linkList));
//	l->head.next = NULL;
//	l->tail = &(l->head);
//	return l;
//}
//
//void clearLinkList(linkList* l) {
//	clearNode(l);
//	free(l);
//}
//
//void clearNode(linkList* l) {
//	Node* p = l->head.next;
//	Node* q;
//	while (p) {
//		q = p->next;
//		free(p);
//		p = q;
//	}
//
//}
//
//int frontLinkList(linkList* l) {
//	if (l->head.next == NULL) {
//		return 0;
//	}
//	return l->head.next->date;
//}
//
//void insertLinkList(linkList* l, int val) {
//	Node* p = getNewNode(val);
//	l->tail->next = p;
//	l->tail = p;
//}
//
//Node* getNewNode(int val) {
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->date = val;
//	p->next = NULL;
//	return p;
//}
//
//void eraseLinkList(linkList* l) {
//	Node* p = l->head.next;
//	l->head.next = l->head.next->next;
//	if (p == l->tail) {
//		l->tail = &(l->head);
//	}
//	free(p);
//}
//
//void output_Queue(Queue* q) {
//	output_LinkList(q->l,q->count);
//}
//
//int output_LinkList(linkList* l,int count) {
//	if (l->head.next == NULL) {
//		return 0;
//	}
//	Node* p = l->head.next;
//	int i = 0;
//	while (i<count) {
//		printf("%d\n", p->date);
//		p = p->next;
//		i++;
//	}
//	printf("\n\n");
//	return 0;
//}