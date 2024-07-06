#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node{
	node *fail;
	node *ch[26];
	int cnt;
	node(){
		fail = NULL;
		memset(ch,0,sizeof(ch));
		cnt = 0;
	}
};
node *srt,*rt;

void init(){
	srt = new node,rt = new node;
	rt->fail = srt;
	for(int i = 0;i<26;i++)srt->ch[i] = rt;
	srt->cnt = -1;
}

void ins(char *s){
	node *t = rt;
	int len = strlen(s);
	for(int i = 0;i<len;i++){
		int ind = s[i]-'a';
		if(!t->ch[ind])t->ch[ind]=new node;
		t = t->ch[ind];
	}
	t->cnt++;
}

void build_ac(){
	queue<node*> q;
	q.push(rt);
	while(!q.empty()){
		node *t;
		t = q.front();
		q.pop();
		for(int i = 0;i<26;i++){
			if(t->ch[i]){
				t->ch[i]->fail = t->fail->ch[i];
				q.push(t->ch[i]);
			}else t->ch[i]=t->fail->ch[i];
		}
	}
}

int query(char *s){
	int ans = 0;
	node *t = rt;
	int len = strlen(s);
	for(int i = 0;i<len;i++){
		int ind = s[i]-'a';
		t = t->ch[ind];
		for(node *u = t;u->cnt!=-1;u=u->fail){
			ans+=u->cnt;
			u->cnt = -1;
		}
	}
	return ans;
}

int main(){
	int T;
	char s1[1000005],s2[55];
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		init();
		for(int i = 0;i<n;i++){
			scanf("%s",s2);
			ins(s2);
		}
		build_ac();
		scanf("%s",s1);
		cout<<query(s1)<<endl;
	}
	return 0;
}
