#include<bits/stdc++.h>

using namespace std;
const int inf = 0x7fffffff;
const int MaxLevel = 16;
struct Node{
	int val,sum[MaxLevel];
	struct Node* fw[MaxLevel];
};
Node* update[MaxLevel],*head,totoal;
int n,k,level,mxk,mnk,tot[MaxLevel],total;

void find(int val){
	Node* p = head;
	tot[level]=0;
	for(int i = level;i>=0;i--){
		while(p->fw[i]&&p->fw[i]->val<val)
			tot[i]+=p->sum[i],p=p->fw[i];
		if(i>0)tot[i-1]=tot[i];
		update[i]=p;
	} 
}

int getrandlevel(){
	int lay=0;
	while(rand()&1&&lay<MaxLevel)lay++;
	return lay;
}

void ins(int val){
	int lay = getrandlevel();
	if(lay>level){
		for(int i = level+1;i<=lay;i++)head->sum[i]=total;
		level=lay;
	}
	find(val);
	Node* p,*s;
	s= new Node;
	s->val=val;
	for(int i = 0;i<MaxLevel;i++){
		s->fw[i]=NULL;
		s->sum[i]=0;
	}
	for(int i = 0;i<=lay;i++){
		s->fw[i]=update[i]->fw[i];
		update[i]->fw[i]=s;
		s->sum[i]=update[i]->sum[i]-(tot[0]-tot[i]);
		update[i]->sum[i]-=s->sum[i]-1;
	}
	for(int i = lay+1;i<=level;i++)update[i]->sum[i]++;
}

int query(int k){
	Node* p = head;
	for(int i = level;i>=0;i--){
		while(p&&p->sum[i]<k)k-=p->sum[i],p=p->fw[i];
	}
	return p->fw[0]->val;
}

void init(){
	level=0;
	head = new Node;
	for(int i = 0;i<MaxLevel;i++){
		head->fw[i]=NULL;
		head->sum[i]=0;
	}
	head->val=-inf;
}

int main(){
	while(cin>>n>>k){
		init();
		int val;
		total=0;
		char opt[10];
		while(n--){
			cin>>opt;
			if(opt[0]=='I'){
				cin>>val;
				ins(val);
				total++;
			}else{
				cout<<query(total-k+1)<<endl;
			}
		}
	}
	return 0; 
}
