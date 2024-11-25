#include<bits/stdc++.h>

using namespace std;
const int N = 50;
const int M = 2000;
struct Edges{
	int nxt,v;
}e[M];
int head[N],cnt=0,indeg[N],id[N],flag = 1;
int n,m,vis[N],res[N],have=0;
void add(int u,int v){
	e[++cnt].v = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

void Topo(int k){
	queue<int> q;
	int sum=0,tot=0;
	for(int i = 0;i<n;i++){
		id[i]=indeg[i];
		if(!indeg[i]&&vis[i]){
			q.push(i);
			res[tot++]=i;
			sum++;
		}
	}
	int step = 0;
	while(!q.empty()){
		int m = q.size();
		if(m==1)step++;
		while(m--){
			int u = q.front();q.pop();
			for(int i = head[u];i;i = e[i].nxt){
				int v = e[i].v;
				if(--id[v]==0){
					q.push(v);
					res[tot++]=v;
					sum++;
				}
			}
		}
	}
	if(step==n){
		printf("Sorted sequence determined after %d relations: ",k);
		for(int i = 0;i<n;i++)
			printf("%c",'A'+res[i]);
		printf(".\n");
		flag = 0;
	}else if(sum!=have){
		printf("Inconsistency found after %d relations.\n",k);
		flag = 0;
	}else if(k==m){
		printf("Sorted sequence cannot be determined.\n");
	}
}

int main(){
	cin>>n>>m;
	char opt[20];
	int u,v;
	for(int i = 0;i<m;i++){
		scanf("%s",opt);
		u = opt[0]-'A',v = opt[2]-'A';
		if(!vis[u])have++;
		if(!vis[v])have++;
		vis[u]=vis[v]=1;
		indeg[v]++;
		add(u,v);
		if(flag)Topo(i+1);
	}	
	return 0;
}
