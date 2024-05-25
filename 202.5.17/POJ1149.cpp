#include<bits/stdc++.h>
using namespace std;
const int N = 110;
const int M = 1e4+10;
const int inf = 0x3f3f3f3f;
int cnt,head[N],d[N],a[1010],belong[1010];
struct{
	int v,nxt,cap,flow;
}e[M<<1];



void add(int u,int v,int w){
	e[cnt].v = v;
	e[cnt].cap = w;
	e[cnt].flow = 0;
	e[cnt].nxt = head[u];
	head[u]=cnt++;
}

void adde(int u,int v,int w){
	add(u,v,w);
	add(v,u,0);
}

bool bfs(int s,int t){
	memset(d,0,sizeof(d));
	queue<int> q;
	d[s]=1;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop(); 
		for(int i = head[u];~i;i=e[i].nxt){
			int v = e[i].v;
			if(d[v])continue;
			if(e[i].cap>e[i].flow){
				d[v]=d[u]+1;
				q.push(v);
				if(v==t)return 1;
			}
		}
	}
	return 0;
}

int dfs(int u,int flow,int t){
	if(u==t)return flow;
	int rest = flow;
	for(int i = head[u];~i&&flow;i = e[i].nxt){
		int v = e[i].v;
		if(d[v]==d[u]+1&&e[i].cap>e[i].flow){
			int k = dfs(v,min(rest,e[i].cap-e[i].flow),t);
			if(!k)d[v]=0;
			e[i].flow+=k;
			e[i^1].flow-=k;
			rest-=k; 
		}
	}
	return flow-rest;
}

int Dinic(int s,int t){
	int maxflow = 0;
	while(bfs(s,t)){
		maxflow+=dfs(s,inf,t); 
	}
	return maxflow;
}

void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}

int main(){
    int m,n,k,x,w,d;
    scanf("%d%d",&m,&n);
    init();
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){//n个客户 
        scanf("%d",&k);//钥匙数 
        w=0;
        for(int j=1;j<=k;j++){
            scanf("%d",&x);
            if(belong[x]==0) 
                w+=a[x];
            else
                adde(belong[x],i,inf);
            belong[x]=i;//标记最近打开x猪圈的客户编号
        }
        adde(0,i,w);
        scanf("%d",&d);
        adde(i,n+1,d);
    }
    printf("%d\n",Dinic(0,n+1));
    return 0; 
}
