#include<bits/stdc++.h>

using namespace std;

const int base = 26;
struct Node{
	struct Node *nxt[base];
	int flag;
};

Node *getnewnode(){
	Node *p = new Node;
	for(int i = 0;i<base;i++)p->nxt[i]=NULL;
	p->flag=0;
	return p;
}

void clear(Node *rt){
	if(!rt)return;
	for(int i = 0;i<base;i++)clear(rt->nxt[i]);
	delete rt;
}

void ins(Node *rt,const char *s){
	Node *p = rt;
	for(int i = 0;s[i];i++){
		int ind = s[i]-'a';
		if(p->nxt[ind]==NULL)p->nxt[ind]=getnewnode();
		p=p->nxt[ind]; 
	}
	p->flag=1;
}

int find(Node *rt,const char *s){
	Node *p = rt;
	for(int i = 0;s[i];i++){
		int ind = s[i]-'a';
		p=p->nxt[ind];
		if(!p)return 0;
	}
	return p->flag;
}

void output(Node *rt,int k,char *buff){
	buff[k]='\0';
	if(rt->flag)printf("%s\n",buff);
	for(int i = 0;i<base;i++){
		if(rt->nxt[i]==NULL)continue;
		buff[k]=i+'a';
		output(rt->nxt[i],k+1,buff);
	} 
}

int main(){
	char s[100];
	Node *rt = getnewnode();
	int n,opt;
	while(cin>>opt&&opt){
		cin>>s;
		switch(opt){
			case 1:
				ins(rt,s);			
				break;
			case 2:
				cout<<find(rt,s)<<endl;
				break;
		}
	}
	output(rt,0,s);
	//clear(rt);
	return 0;
}
