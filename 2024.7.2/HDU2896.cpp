#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int K = 126-32;

struct node{
	node *fail;
	node *ch[K];
	int cnt,id;
	node(){
		fail=NULL;
		memset(ch,0,sizeof(ch));
		cnt = id = 0;
	}
}* srt,*rt;

void init(){
	srt = new node,rt = new node;
	rt->fail = srt;
	for(int i = 0;i<K;i++)srt->ch[i]=rt;
	srt->cnt = -1;
}

void ins(char *s,int id){
	node *t = rt;
	int len = strlen(s);
	for(int i = 0;i<len;i++){
		int ind = s[i]-33;
		if(!t->ch[ind])t->ch[ind]=new node;
		t = t->ch[ind];
	}
	t->id=id;
	t->cnt++;
}

void build_ac(){
	queue<node*> q;
	q.push(rt);
	while(!q.empty()){
		node *t;
		t = q.front();
		q.pop();
		for(int i = 0;i<K;i++){
			if(t->ch[i]){
				t->ch[i]->fail = t->fail->ch[i];
				q.push(t->ch[i]);
			}else{
				t->ch[i] = t->fail->ch[i];
			}
		}
	}
}

bool flag [510];

bool query(char *s){
	memset(flag,0,sizeof(flag));
	node *t = rt;
	bool ret = 0;
	int len = strlen(s);
	for(int i = 0;i<len;i++){
		int ind = s[i]-33;
		t = t->ch[ind];
		for(node *u = t;u->cnt!=-1;u=u->fail){
			if(u->cnt==1){
				ret = 1;
				flag[u->id]=1;
			}
		}
	}
	return ret;
}


int main(){
	init();
	int n,m;
	char s1[205],s2[10005];
	cin>>n;
	for(int i = 1;i<=n;i++){
		scanf("%s",s1);
		ins(s1,i);
	}
	build_ac();
	cin>>m;
	int ans = 0;
	for(int i = 1;i<=m;i++){
		scanf("%s",s2);
		if(query(s2)){
			ans++;
			printf("web %d:",i);
			for(int j = 1;j<=n;j++){
				if(flag[j])printf(" %d",j);
			}
			cout<<endl;
		}
	}
	printf("total: %d\n",ans);
	return 0;
}

