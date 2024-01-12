//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//typedef struct Node {
//	struct Node* lchild, * rchild;
//	int key;
//}Node;
//
//Node* getNewNode(int key);
//int clear(Node* root);
//Node* insert(Node* root, int key);
//int dfs(Node* root);
//void bfs(Node* root);
//
//
//int main() {
//	srand((unsigned int)time(NULL));
//	int op = 10;
//	Node* root = NULL;
//	for (int i = 0; i < op; i++) {
//		int key = rand() % 100;
//		root = insert(root, key);
//	}
//	dfs(root);
//	printf("\n\n");
//	bfs(root);
//	clear(root);
//	return 0;
//}
//
//Node* getNewNode(int key) {
//	Node* r = (Node*)malloc(sizeof(Node));
//	r->key = key;
//	r->lchild = NULL;
//	r->rchild = NULL;
//	return r;
//}
//
//int clear(Node* root) {
//	if (root == NULL) {
//		return 0;
//	}
//	clear(root->lchild);
//	clear(root->rchild);
//	free(root);
//	return 0;
//}
//
//Node* insert(Node* root, int key) {
//	if (root == NULL) {
//		return getNewNode(key);
//	}
//	if (rand() % 2)root->lchild = insert(root->lchild, key);
//	else {
//		root->rchild = insert(root->rchild, key);
//	}
//	return root;
//}
//
//int tot = 0;
//
//int dfs(Node* root) {
//	
//	if (root == NULL) {
//		return 0;
//	}
//	int start = 0;
//	int end = 0;
//	tot++;
//	start = tot;
//	if(root->lchild)dfs(root->lchild);
//	if(root->rchild)dfs(root->rchild);
//	tot++;
//	end = tot;
//	printf("%d [%d,%d]\n", root->key, start, end);
//	return 0;
//}
//
//Node* Queue[15];
//int head, tail;
//
//void bfs(Node* root){
//	head = tail = 0;
//	Queue[tail++] = root;
//	while (head < tail) {
//		Node* node = Queue[head];
//		printf("%d\n\n", node->key);
//		if (node->lchild) {
//			Queue[tail++] = node->lchild;
//			printf("%d -> %d(left)\n", node->key, node->lchild->key);
//		}
//		if (node->rchild) {
//			Queue[tail++] = node->rchild;
//			printf("%d -> %d(right)\n", node->key, node->rchild->key);
//		}
//		head++;
//		printf("\n\n");
//	}
//}