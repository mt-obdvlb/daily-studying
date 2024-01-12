//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>	
//#include<string.h>
//#include<stdbool.h>
//
//
//#define swapInt(a,b) {\
//	int __c = (a);\
//	(a) = (b);\
//	(b) = __c;\
//}
//
//
//typedef struct Node {
//	struct Node* next;
//	char* s;
//}Node;
//
//typedef struct HashTable {
//	Node* data;
//	int count, size;
//}HashTable;
//
//#define swapNode(a,b){\
//	Node* p = a;\
//	a = b;\
//	b = p;\
//}
//
//Node* getNewNode(const char* str);
//HashTable* getNewHashTable(int n);
//void insert(HashTable* h,const char* str);
//void expand(HashTable* h);
//void clearNode(Node* p);
//void clearHashTable(HashTable* h);
//void output(HashTable* h);
//bool find(HashTable* h,const char* str);
//int hash_func(const char* str);
//void swapHashTable(HashTable* h, HashTable* new_h);
//
//int main() {
//	srand((unsigned int)time(NULL));
//	char s[100];
//#define MAX_N 2
//	HashTable* h = getNewHashTable(MAX_N);
//	while (~scanf("%s", s)) {
//		if (strcmp(s, "end") == 0) break;
//		insert(h, s);
//	}
//	output(h);
//	while (~scanf("%s", s)) {
//		printf("find(%s) = %d\n", s, find(h, s));
//	}
//#undef MAX_N
//	return 0;
//}
//
//Node* getNewNode(const char* str) {
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->s = (char*)malloc(sizeof(char) * 100);
//	strcpy(p->s, str);
//	p->next = NULL;
//	return p;
//}
//
//HashTable* getNewHashTable(int n){
//	HashTable* h = (HashTable*)malloc(sizeof(HashTable));
//	h->data = (Node*)malloc(sizeof(Node)*n);
//	h->count = 0;
//	h->size = n;
//	for (int i = 0; i < h->size; i++) {
//		h->data[i].next = NULL;
//	}
//	return h;
//}
//
//void clearHashTable(HashTable* h) {
//	if (h == NULL) {
//		return;
//	}
//	for (int i = 0; i < h->size; i++) {
//		Node* p = h->data[i].next, * q;
//		while (p) {
//			q = p->next;
//			clearNode(p);
//			p = q;
//		}
//	}
//	free(h->data);
//	free(h);
//}
//
//void clearNode(Node* p) {
//	if (p == NULL) {
//		return;
//	}
//	if (p->s)free(p->s);
//	free(p);
//}
//
//void insert(HashTable* h, const char* str) {
//	if (h->count >= h->size * 2) {
//		expand(h);
//	}
//	int hcode = hash_func(str);
//	int ind = hcode % h->size;
//	Node* p = h->data[ind].next,*q = getNewNode(str);
//	h->data[ind].next = q;
//	q->next = p;
//	h->count++;
//}
//
//void output(HashTable* h) {
//	if (h == NULL) {
//		return;
//	}
//	for (int i = 0; i < h->size; i++) {
//		Node* p = h->data[i].next;
//		while (p) {
//			printf("%s -> ", p->s);
//			p = p->next;
//		}
//		printf("\n");
//	}
//	printf("\n\n");
//}
//
//void expand(HashTable* h) {
//	printf("Expand!\n");
//	HashTable* new_hash = getNewHashTable(h->size * 2);
//	for (int i = 0; i < h->size; i++) {
//		Node* p = h->data[i].next;
//		while (p) {
//			insert(new_hash, p->s);
//			p = p->next;
//		}
//	}
//	swapHashTable(new_hash, h);
//	clearHashTable(new_hash);
//}
//
//void swapHashTable(HashTable* new_h, HashTable* h) {
//	swapInt(new_h->count, h->count);
//	swapInt(new_h->size, h->size);
//	swapNode(new_h->data, h->data);
//}
//
//bool find(HashTable* h, const char* str) {
//	int hcode = hash_func(str);
//	int ind = hcode % h->size;
//	Node* p = h->data[ind].next;
//	while (p) {
//		if (strcmp(p->s, str) == 0) {
//			return true;
//		}
//		p = p->next;
//	}
//	return false;
//}
//
//int hash_func(const char* str) {
//	int seed = 131, h = 0;
//	for (int i = 0; str[i]; i++) {
//		h = h * seed + str[i];
//	}
//	return h & 0x7fffffff;
//}