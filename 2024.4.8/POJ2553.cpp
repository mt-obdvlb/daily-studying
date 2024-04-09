#include<iostream>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

const int MAXN = 5005;

int head[MAXN],to[MAXN],belong[MAXN],degee[MAXN],nxt[MAXN],dfn[MAXN],low[MAXN],ins[MAXN];
int n,m,tot,cnt,id;
stack<int> st;

void add(int u,int v){
	nxt[++tot] = head[u];
	to[tot] = v;
	head[u] = tot; 
}

void dfs(int u){
	st.push(u);
	ins[u] = 1;
	dfn[u] = low[u] = ++cnt;
	for(int i = head[u];i;i=nxt[i]){
		int v = to[i];
		if(!dfn[v]){
			dfs(v);
			low[u] = min(low[u],low[v]); 
		}else if(ins[u]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		int v;
		id++;
		do{
			v = st.top();
			st.pop();
			belong[v] =id;
		}while(u!=v);
	}
}

int main(){
	while(cin>>n&&n&&cin>>m){
		int u,v;
		tot = cnt = 0;
		memset(head,0,sizeof(head));
		memset(to,0,sizeof(head));
		memset(degee,0,sizeof(head));
		memset(nxt,0,sizeof(head));
		memset(low,0,sizeof(head));
		memset(dfn,0,sizeof(head));
		memset(belong,0,sizeof(head));
		memset(ins,0,sizeof(head));
		while(m--){
			cin>>u>>v;
			add(u,v);
		}		
		for(int i = 1;i<=n;i++){
			if(!dfn[i])dfs(i);
		}
		for(int u = 1;u<=n;u++){
			for(int i = head[u];i;i=nxt[i]){
				int v = to[i];
				if(belong[v]!=belong[u])degee[belong[u]]++;
			}
		}
		for(int i = 1;i<=n;i++){
			if(!degee[belong[i]])cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}
