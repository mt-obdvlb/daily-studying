#include<bits/stdc++.h>

using namespace std;
const int inf = 0x7fffffff;
const int Max_Level = 16;
struct Node{
	int num,val;
	struct Node *forward[Max_Level];
};

Node *head, *update[Max_Level];
int level,max_k,min_k;

void init(){
	level = 0;
	max_k=-inf,min_k=inf;
	head = new Node;
	for(int i = 0;i<Max_Level;i++){
		head->forward[i]=NULL;
	}
	head->val=-inf;
} 
int randlevel(){
	int lay = 0;
	while(rand()%2&&lay<Max_Level-1)lay++;
	return lay;
}

Node* find(int val){
	Node* p =head;
	for(int i = level;i>=0;i--){
		while(p->forward[i]&&p->forward[i]->val<val)p=p->forward[i];
		update[i]=p;
	}
	return p;
}

void ins(int num,int val){
	if(val>max_k)max_k=val;
	if(val<min_k)min_k=val;
	Node* p,*s;
	int lay =randlevel();
	if(lay>level)level=lay;
	p=find(val);
	s=new Node;
	s->num=num,s->val = val;
	for(int i = 0;i<Max_Level;i++)s->forward[i]=NULL;
	for(int i = 0;i<=lay;i++){
		s->forward[i]=update[i]->forward[i];
		update[i]->forward[i]=s;
	} 
}

void del(int flag){
	int d;
	if(flag)d=max_k;
	else d=min_k;
	if(d==inf||d==-inf){
		cout<<"0"<<endl;
		return; 
	}
	Node* p = find(d);
	if(p->forward[0]&&p->forward[0]->val==d){
		cout<<p->forward[0]->num<<endl;
		if(p->val==-inf&&p->forward[0]->forward[0]){
			max_k=-inf,min_k=inf;
		}else{
			if(flag)max_k=p->val;
			else min_k=p->forward[0]->forward[0]->val;
		}
		for(int i = level;i>=0;i--){
			if(update[i]->forward[i]&&update[i]->forward[i]->val==d){
				update[i]->forward[i]=update[i]->forward[i]->forward[i];
			}
		} 
	}
}

int main(){
	init();
	int op,num,val;
	while(cin>>op&&op){
		if(op==1){
			cin>>num>>val;
			ins(num,val);
		}else if(op==2)del(1);
		else del(0);
	}
	return 0;
}
