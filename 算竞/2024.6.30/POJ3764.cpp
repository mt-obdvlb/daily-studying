#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e5+10;
int n,cnt,mx,tot;
int trie[N*32][2],head[N],dx[N];
struct Edges{
	int v,w,nxt;
}e[N<<1];

void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}

void init(){
	memset(head,0,sizeof(head));
	memset(trie,0,sizeof(trie));
	cnt = mx = 0;
	tot = 1;
}

void dfs(int u,int fa){
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].v,w = e[i].w;
		if(v==fa)continue;
		dx[v] = dx[u]^w;
		dfs(v,u);
	}
}

void ins(int num){
	int p = 1;
	for(int i = 30;i>=0;i--){
		bool k = num&(1<<i);
		if(!trie[p][k])trie[p][k]=++tot;
		p = trie[p][k];
	}
}

int find(int num){
	int p = 1,res = 0;
	for(int i = 30;i>=0;i--){
		bool k = num&(1<<i);
		if(trie[p][k^1]){
			res += 1 << i;
			p = trie[p][k^1];
		}else{
			p = trie[p][k];
		}
	}
	return res;  
}

int main(){
	int u,v,w;
	while(~scanf("%d",&n)){
		init();
		for(int i = 1;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);	
			add(u+1,v+1,w);
			add(v+1,u+1,w);
		}
		dx[1]=0;
		dfs(1,0);
		ins(dx[1]);
		for(int i = 2;i<=n;i++){
			mx = max(mx,find(dx[i]));
			ins(dx[i]);
		}
		cout<<mx<<endl;
	}
	return 0;
}
