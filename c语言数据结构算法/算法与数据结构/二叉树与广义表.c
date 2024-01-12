//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<string.h>
//
//#define MAX_OP 10
//#define KEY(n) (n?n->key:-11)
//int len = 0;
//char buff[1000];
//
//typedef struct Node {
//	struct Node* lchild, * rchild;
//	int key;
//}Node;
//
//Node* getNewNode(int key);
//Node* getRandomBinaryTree(int n);
//void clean(Node* root);
//Node* insert(Node* root, int key);
//void serialize(Node* root);
//void __serialize(Node* root);
//Node* reserialize(char buff[],int len);
//void output(Node* root);
//void print(Node* node);
//
//int main() {
//	srand((unsigned int)time(NULL));
//	Node* root = getRandomBinaryTree(MAX_OP);
//	output(root);
//	serialize(root);
//	printf("%s\n\n", buff);
//	root = reserialize(buff,len);
//	output(root);
//	clean(root);
//	
//	return 0;
//}
//
//Node* getNewNode(int key) {
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->key = key;
//	p->lchild = p->rchild = NULL;
//	return p;
//}
//
//void clean(Node* root) {
//	if (!root) {
//		return;
//	}
//	clean(root->lchild);
//	clean(root->rchild);
//	free(root);
//}
//
//Node* getRandomBinaryTree(int n) {
//	Node* root = NULL;
//	for (int i = 0; i < n; i++) {
//		root = insert(root,rand() % 100); 
//	}
//	return root;
//}
//
//Node* insert(Node* root, int key) {
//	if (!root) {
//		return getNewNode(key);
//	}
//	if (rand() % 2) {
//		root->lchild = insert(root->lchild, key);
//	}
//	else {
//		root->rchild = insert(root->rchild, key);
//	}
//	return root;
//}
//
//void serialize(Node* root) {
//	memset(buff, 0, sizeof(buff));
//	len = 0;
//	__serialize(root);
//}
//
//void __serialize(Node* root) {
//	if (!root) {
//		return;
//	}
//	len += sprintf(buff + len, "%d", root->key);
//	if (!root->lchild && !root->rchild) {
//		return;
//	}
//	len += sprintf(buff + len, "[");
//	__serialize(root->lchild); 
//	if (root->rchild) {
//		len += sprintf(buff + len, ",");
//		__serialize(root->rchild);
//	}
//	len += sprintf(buff + len, "]");
//}
//
//Node* reserialize(char buff[], int len) {
//	Node** s = (Node**)malloc(sizeof(Node*));
//	int top = -1;
//	int scode = 0;
//	int flag = 0;
//	int key = 0;
//	Node* root = NULL,*p = NULL;
//	for (int i = 0; buff[i]; i++) {
//		switch (scode) {
//			case 0:
//				if (buff[i] >= '0' && buff[i] <= '9') {
//					scode = 1;
//				}
//				else if (buff[i] == '[') {
//					scode = 2;
//				}
//				else if (buff[i] == ',') {
//					scode = 3;
//				}
//				else if (buff[i] == ']') {
//					scode = 4;
//				}
//				i--;
//				break;
//			case 1:
//				key = 0;
//				while (buff[i] >= '0' && buff[i] <= '9') {
//					key = key * 10 + (buff[i] - '0');
//					i++;
//				}
//				p = getNewNode(key);
//				if (flag == 0 && top >= 0) {
//					s[top]->lchild = p;
//				}
//				if (flag == 1 && top >= 0) {
//					s[top]->rchild = p;
//				}
//				flag = 0;
//				i--;
//				scode = 0;
//				break;
//			case 2:
//				s[++top] = p;
//				scode = 0;
//				flag = 0;
//				break;
//			case 3:
//				flag = 1;
//				scode = 0;
//				break;
//			case 4:
//				root = s[top];
//				top--;
//				scode = 0;
//				break;
//		}
//	}
//	return root;
//}
//
//void output(Node* root) {
//	if (root == NULL) return;
//	print(root);
//	output(root->lchild);
//	output(root->rchild);
//	return;
//}
//
//void print(Node* node) {
//	printf("%d(%d, %d)\n", KEY(node),
//		KEY(node->lchild),
//		KEY(node->rchild)
//	);
//	return;
//}
