#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
	int key,h;
 	struct Node* lchild,*rchild;
}Node;


Node __NIL;
#define NIL (&__NIL)
#define H(n) (n->h)
#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define K(n) (n->key)
__attribute__((constructor))
void init_NIL(){
	NIL->key = -1;
	NIL->h = 0;
	NIL->lchild = NIL ->rchild = NIL;
}

Node* getNewNode(int key){
	Node* p =  (Node*) malloc(sizeof(Node));
	p->h = 1;
	p->key = key;
	p->lchild =NIL;
	p->rchild = NIL;
	return p;
}

void clear(Node* root){
	if(root == NIL){
		return ;
	}
	clear(root->lchild);
	clear(root->rchild);
	free(root);
}

void update_height(Node* root){
	H(root) = ((H(L(root)>H(R(root))))?L(root):R(root))+1;
}

Node* left_rotate(Node* root){
	Node* new_root = root->rchild;
	root->rchild = new_root->lchild;
	new_root->lchild = root;
	update_height(root);
	update_height(new_root);
	return new_root;
}

Node* right_rotate(Node* root){
	Node* new_root = root->lchild;
	root->lchild = new_root->rchild;
	new_root->rchild = root;
	update_height(root);
	update_height(new_root);
	return new_root;
}

Node* maintain(Node* root){
	if(abs(H(L(root))-H(R(root)))<=1){
		return root;
	}
	if(H(L(root))>H(R(root)){
		if(H(R(L(root)))>H(L(L(root))){
			root->lchild = left_rotate(root->lchild);
		}
		root = right_rotate(root); 
	}else{
		if(H(L(R(root)))>H(R(R(root))){
			root->rchild = right_rotate(root->rchild);
		}
		root = left_rotate(root);
	}
	return root;
}

Node* insert(Node* root,int key){
	if(root == NIL){
		return getNewNode(key);
	}
	if(root ->key == key){
		return root;
	}
	if(key<root->key){
		root->lchild = insert(root->lchild,key);
	}else{
		root->rchild = insert(root->rchild,key);
	}
	update_height(root)
	return maintain(root);
}

int main(){
	
	return 0;
}








