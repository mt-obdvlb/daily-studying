#include<bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 1e4;
const int M = 1e5;
int n,cnt,head[N],vis[N],match[N];
struct Edges{
	int v,nxt;
}e[M<<1];

void add(int u,int v,int w){
	e[cnt].v=v;
	e[cnt].nxt = head[u];
	head[u] = cnt++;
}


bool maxmatch(int u){
	for(int i = head[u];~i;i = e[i].nxt){
		int v = e[i].v;
		if(!vis[v]){
			vis[v]=1;
			if(!match[v]||maxmatch(match[v])){
				match[v]=u;
				return true;
			}
		}
	}
	return false;
}

int main(){
	
	return 0;
}
