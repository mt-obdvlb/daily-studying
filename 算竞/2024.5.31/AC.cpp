#include<bits/stdc++.h>

using namespace std;

struct node{
	int flag;
	struct node *nxt[26];
	struct node *fail;
	const char *s;
};

node *getnewnode(){
	node *p = new node;
	p->flag=0;
	p->fail=NULL;
	p->s=NULL;
	for(int i = 0;i<26;i++)p->nxt[i]=NULL;
	return p;
}

void clear(node *rt){
	if(rt==NULL)return;
	for(int i = 0;i<26;i++)clear(rt->nxt[i]);
	delete rt;
}

void ins(node *rt,const char *s){
	node *p = rt;
	for(int i = 0;s[i];i++){
		int ind = s[i]-'a';
		if(p->nxt[ind]==NULL)p->nxt[ind]=getnewnode();
		p=p->nxt[ind];
	}
	p->s=strdup(s);
	p->flag=1;
}

void build_ac(node *rt){
	queue<node*> q;
	for(int i = 0;i<26;i++){
		if(!rt->nxt[i])continue;
		rt->nxt[i]->fail = rt;
		q.push(rt->nxt[i]);
	}
	while(!q.empty()){
		node *cur = q.front(),*p;q.pop();
		for(int i = 0;i<26;i++){
			if(!cur->nxt[i])continue;
			 p = cur->fail;
			 while(p&&!p->nxt[i])p=p->fail;
			 if(!p)p=rt;
			 else p = p->nxt[i];
			 cur->nxt[i]->fail = p;
			 q.push(cur->nxt[i]);
		}
	}
}

void find_ac(node *rt,const char *s){
	node *p = rt,*q;
	for(int i = 0;s[i];i++){
		int ind = s[i]-'a';
		while(p&&!p->nxt[ind])p=p->fail;
		if(!p)p=NULL;
		else p =p->nxt[ind];
		q = p;
		while(q){
			if(q->flag)cout<<q->s<<endl;
			q=q->fail;
		}
	}
}

int main(){
	node *rt = getnewnode();	
	int n;
	char s[100];
	cin>>n;
	while(n--){
		cin>>s;
		ins(rt,s);
	}
	build_ac(rt);
	cin>>s;
	find_ac(rt,s);
	return 0;
}
