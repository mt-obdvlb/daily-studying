#include<bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int head[MAXN],to[MAXN],nxt[MAXN],ins[MAXN],low[MAXN],dfn[MAXN];
int belong[MAXN],indeg[MAXN],outdeg[MAXN];
int n,tot,cnt,id,ans1,ans2;

stack<int> st;

void add(int u,int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] =tot;
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
		 }else if(ins[v])low[u] = min(low[u],dfn[v]);
	 }
	 if(dfn[u]==low[u]){
	 	int v;
	 	id++;
	 	do{
	 		v = st.top();
	 		st.pop();
	 		belong[v] = id;
	 		ins[v] = 0;
		 }while(v!=u);
	 }
}

int main(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		int v;
		while(cin>>v&&v){
			add(i,v);		
		}
	}
	for(int i = 1;i<=n;i++)if(!dfn[i])dfs(i);
	for(int u = 1;u<=n;u++){
		int v;
		for(int j = head[u];j;j=nxt[j]){
			v = to[j];
			if(belong[u]!=belong[v]){
				outdeg[belong[u]]++;
				indeg[belong[v]]++;
			}
		}
	}
	if(id==1){
		cout<<1<<endl;
		cout<<0<<endl;
		return 0;
	}
	for(int i = 1;i<=id;i++){
		if(!indeg[i])ans1++;
		if(!outdeg[i])ans2++; 
	}	
	cout<<ans1<<endl<<max(ans1,ans2)<<endl;
	return 0;
}
