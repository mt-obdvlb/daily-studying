//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define OP_MAX 10
//
//
//typedef struct Node {
//	int date;
//	struct Node* next;
//}Node;
//
//Node* getNewNode(int val);
//void clear(Node* head);
//Node* insert(Node* head, int val, int pos);
//void output_node(Node* head);
//
//int main() {
//	srand((unsigned int)time(NULL));
//	Node* head = NULL;
//	for (int i = 0; i < OP_MAX; i++) {
//		int pos = rand() % (i + 1);
//		int val = rand() % 100;
//		head = insert(head, val, pos);
//		output_node(head);
//	}
//	clear(head);
//	return 0;
//}
//
//Node* getNewNode(int val) {
//	Node* node = (Node*)malloc(sizeof(Node));
//	node->next = NULL;
//	node->date = val;
//	return node;
//}
//
//void clear(Node* head) {
//	for (Node* p = head, *q=NULL; p; p = q) {
//		q = p->next;
//		free(p);
//	}
//}
//
//Node* insert(Node* head, int val, int pos) {
//	
//
//	//if (0 == pos) {
//	//	Node* p = getNewNode(val);
//	//	p->next = head;
//	//	return p;
//	//}
//	//else {
//	//	Node* p = head,*q;
//	//	for (int n = 0; n < pos - 1; n++) {
//	//		p = p->next;
//	//	}
//	//	q = p->next;
//	//	Node* node = getNewNode(val);
//	//	p->next = node;
//	//	node->next = q;
//	//	return head;
//
//	
//
//	Node new_head, * p = &new_head, * node = getNewNode(val);
//	new_head.next = head;	
//	int n = 0;
//	for(n = 0;n<pos;n++){
//		p = p->next;
//	}
//	node->next = p->next;
//	p->next = node;
//	return new_head.next;
//}
//
//void output_node(Node* head) {
//	int n = 0;
//	for (Node* p = head; p; p = p->next) {
//		n += 1;
//	}
//	for (int i = 0; i < n; i++) {
//		printf("%3d", i);
//		printf("  ");
//	}
//	printf("\n");
//	for (Node* p = head; p; p = p->next) {
//		printf("%3d", p->date);
//		printf("->");
//	}
//	printf("\n");
//}