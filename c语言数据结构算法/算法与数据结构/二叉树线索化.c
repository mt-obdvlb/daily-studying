//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//#define OP_MAX 10
//
//typedef struct Node {
//	struct Node* lchild, *rchild;
//	int key;
//	int ltag, rtag;
//}Node;
//
//Node* pre_node = NULL, * inorder_root = NULL;
//
//
//Node* getNewNode(int key);
//void clear(Node* root);
//Node* insert(Node* root, int key);
//void pre_order(Node* root);
//void in_order(Node* root);
//void post_order(Node* root);
//void __build_inorder_thread(Node* root);
//void build_inorder_thread(Node* root);
//Node* getNext(Node* root);
//
//int main() {
//	srand((unsigned int)time(NULL));
//	Node* root = NULL;
//	int i = 0;
//	for (i = 0; i < OP_MAX; i++) {
//		root = insert(root, rand() % 100);
//	}
//	pre_node = NULL;
//	inorder_root = NULL;
//	build_inorder_thread(root);
//
//	pre_order(root);
//	printf("\n");
//	in_order(root);
//	printf("\n");
//	post_order(root);
//	printf("\n");
//
//
//	Node* node = inorder_root;
//	while (node) {
//		printf("%d ", node->key);
//		node = getNext(node);
//	}
//	clear(root);
//	return 0;
//}
//
//Node* getNewNode(int key) {
//	Node* root = (Node*)malloc(sizeof(Node));
//	root->key = key;
//	root->ltag = root->rtag = 1;
//	root->lchild = root->rchild = NULL;
//	return root;
//}
//
//void clear(Node* root) {
//	if (!root) {
//		return;
//	}
//	if (root->ltag) { clear(root->lchild); }
//	if (root->rtag) { clear(root->rchild); }
//	free(root);
//}
//
//Node* insert(Node* root, int key) {
//	if (!root) {
//		return getNewNode(key);
//	}
//	if (rand() % 2) {
//		root->lchild = insert(root->lchild, key);
//	}else {
//		root->rchild = insert(root->rchild, key);
//	}
//	return root;
//}
//
//void pre_order(Node* root) {
//	if (!root ) {
//		return;
//	}
//	printf("%d ", root->key);
//	if (root->ltag) {
//		pre_order(root->lchild);
//	}
//	if (root->rtag) {
//		pre_order(root->rchild);
//	}
//
//}
//
//void in_order(Node* root) {
//	if (!root ) {
//		return;
//	}
//	if (root->ltag) {
//		in_order(root->lchild);
//	}
//	printf("%d ", root->key);
//	if (root->rtag) {
//		in_order(root->rchild);
//	}
//
//}
//
//void post_order(Node* root) {
//	if (!root ) {
//		return;
//	}
//	if (root->ltag) {
//		post_order(root->lchild);
//	}
//	if (root->rtag) {
//		post_order(root->rchild);
//	}
//	printf("%d ", root->key);
//
//}
//
//
//void __build_inorder_thread(Node* root) {
//	if (!root ) {
//		return;
//	}
//	if (root->ltag) {
//		__build_inorder_thread(root->lchild);
//	}
//	if (!inorder_root) {
//		inorder_root = root;
//	}
//	if (!root->lchild ) {
//		root->ltag = 0;
//		root->lchild = pre_node;
//	}
//	if (pre_node&&!pre_node->rchild ) {
//		pre_node->rchild = root;
//		pre_node->rtag = 0;
//	}
//	pre_node = root;
//	if (root->rtag ) {
//		__build_inorder_thread(root->rchild);
//	}
//	
//}
//
//void build_inorder_thread(Node* root) {
//	__build_inorder_thread(root);
//	pre_node->rchild = NULL;
//	pre_node->rtag = 0;
//}
//
//Node* getNext(Node* root) {
//	if (!root->rtag ) {
//		return root->rchild;
//	}
//	root = root->rchild;
//	while (root->ltag && root->lchild) {
//		root = root->lchild;
//	}
//	return root;
//}