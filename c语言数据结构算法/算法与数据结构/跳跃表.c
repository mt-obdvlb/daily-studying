//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>	
//#include<limits.h>
//
//typedef struct Node {
//	int key,level;
//	struct Node* next,*down,*up;
//}Node;
//
//typedef struct Skiplist {
//	Node* head, * tail;
//	int max_level;
//}Skiplist;
//
//inline Node* getNewNode(int key,int n);
//Skiplist* getNewSkiplist(int n);
//void clearSkiplist(Skiplist* s);
//inline void clearNode(Node* p);
//void insert(Skiplist* s, int x);
//inline int RandLevel(Skiplist* s);
//void output(Skiplist* s);
//Node* find(Skiplist* s, int x);
//
//
//int main() {
//	srand((unsigned int)time(NULL));
//#define MAX_LEVEL 32
//	Skiplist* s = getNewSkiplist(MAX_LEVEL);
//#undef MAX_LEVEL
//	int x = 0;
//	while (~scanf("%d", &x)) {
//		if (x == -1) {
//			break;
//		}
//		insert(s,x);
//	}
//	output(s);
//	while (~scanf("%d", &x)) {
//		if (x == -1) {
//			break;
//		}
//		Node* p = find(s, x);
//		if (p) {
//			printf("Find! key = %d ,level = %d\n", p->key, p->level);;
//		}
//		else {
//			printf("NO FIND!\n");
//		}
//	}
//	clearSkiplist(s);
//	return 0;
//}
//
//inline Node* getNewNode(int key, int n) {
//	Node* nodes = (Node*)malloc(sizeof(Node) * n);
//	for (int i = 0; i < n; i++) {
//		nodes[i].key = key;
//		nodes[i].next = NULL;
//		nodes[i].down = i ? nodes + i - 1 : NULL;
//		nodes[i].up = i + 1 < n ? nodes + i + 1 : NULL;
//		nodes[i].level = i;
//	}
//	return nodes + n - 1;
//}
//
//Skiplist* getNewSkiplist(int n) {
//	Skiplist* s = (Skiplist*)malloc(sizeof(Skiplist));
//	s->head = getNewNode(INT_MIN, n);
//	s->tail = getNewNode(INT_MAX, n);
//	s->max_level = n;
//	Node* p = s->head, * q = s->tail;
//	while (p) {
//		p->next = q;
//		p = p->down;
//		q = q->down;
//	}
//	return s;
//}
//
//void clearSkiplist(Skiplist* s) {
//	Node* p = s->head,*q;
//	while (p->level != 0) {
//		p = p->down;
//	}
//	while (p) {
//		q = p->next;
//		clearNode(p);
//		p = q;
//	}
//	free(s);
//}
//
//inline void clearNode(Node* p) {
//	if (!p) {
//		return;
//	}
//	free(p);
//}
//
//Node* find(Skiplist* s, int x) {
//	Node* p = s->head;
//	while (p && p->key != x) {
//		if (p->next->key <= x) {
//			p = p->next;
//		}
//		else {
//			p = p->down;
//		}
//	}
//	return p;
//}
//
//void insert(Skiplist* s, int x) {
//	int level = RandLevel(s);
//	Node* p = s->head,*q = getNewNode(x,level),*a;
//	while(p->level + 1 != level) {
//		p = p->down;
//	}
//	while (p) {
//		while(p->next&&p->next->key <= q->key) {
//			p = p->next;
//		}
//		a = p->next;
//		p->next = q;
//		q->next = a;
//		p = p->down;
//	}
//}
//
//inline int RandLevel(Skiplist* s) {
//	double p = 1.0 / 10.0;
//	int level = 1;
//#define MAX_VAL 10000
//	while (rand() % MAX_VAL * 1.0 / MAX_VAL >= p) {
//		level++;
//	}
//#undef MAX_VAL
//#define min(a,b) (a)<(b)? (a):(b)
//	return min(s->max_level ,level);
//}
//
//void output(Skiplist* s) {
//	Node* p = s->head,*q;
//	while (p->level != 0) {
//		p = p->down;
//	}
//	p = p->next;
//	while (p->next&&p->key != s->tail->key) {
//		q = p;
//		while(q->up){
//			q = q->up;
//		}
//		printf("key: %d , level: %d \n", q->key, q->level+1);
//		p = p->next;
//	}
//	printf("\n\n\n\n");
//}