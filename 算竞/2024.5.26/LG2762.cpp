#include<bits/stdc++.h>
#include<sstream>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=10010;
const int M=10010;
int n,m,s,t,cnt,sum=0;
int head[N],ans[N],pre[N],h[N],g[N];
bool vis[N];
struct Edge{
   int v,nxt;
   int cap,flow;
}e[M<<1];
void add(int u,int v,int w){
	e[cnt].v=v;
	e[cnt].cap=w;
	e[cnt].flow=0;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
}

void adde(int u,int v,int w){
	add(u,v,w);
	add(v,u,0);
}

void set_h(int t){
	memset(h,-1,sizeof(h));
	memset(g,0,sizeof(g));
	queue<int> q;
	q.push(t);
	h[t]=0;
	while(!q.empty()){
		int u = q.front();q.pop();
		g[h[u]]++;
		for(int i =head[u];~i;i=e[i].nxt){
			int v = e[i].v;
			if(h[v]==-1){
				h[v]=h[u]+1;
				q.push(v);
			}
		}
	}
}

int ISAP(int s,int t,int n){
	set_h(t);
	int u = s,d,ans=0;
	while(h[s]<n){
		int i = head[u];
		if(u==s)d=inf;
		for(;~i;i=e[i].nxt){
			int v = e[i].v;
			if(e[i].cap>e[i].flow&&h[u]==h[v]+1){
				u = v;
				pre[v]=i;
				d=min(d,e[i].cap-e[i].flow);
				if(u==t){
					while(u!=s){
						int j = pre[u];
						e[j].flow+=d;
						e[j^1].flow-=d;
						u = e[j^1].v;	
					}
					ans+=d;
					d=inf;
				}
				break;
			}
		}
		if(i==-1){
			if(--g[h[u]]==0)break;
			int hmin = n-1;
			for(int j = head[u];~j;j=e[j].nxt){
				if(e[j].cap>e[j].flow)hmin=min(hmin,h[e[j].v]);
			}
			h[u]=hmin+1;
			g[h[u]]++;
			if(u!=s)u=e[pre[u]^1].v;
		}
	}
	return ans;
}

void init(){
	cnt=0;
	memset(head,-1,sizeof(head));
}

void readin() {	//建图 
	init();
	char c[N];
	
	scanf("%d%d",&n,&m);
	s=0,t=n+m+1;
	for(int i=1;i<=n;i++){
		int v;
		scanf("%d",&v);
		sum+=v;
		adde(s,i,v);
		memset(c,0,sizeof(c));
		cin.getline(c,N);
		int ulen=0,num;
		while(sscanf(c+ulen,"%d",&num)==1) {
			adde(i,n+num,inf);
			if(num==0) ulen++;
			else while(num){
					num/=10;
					ulen++;
				}
			ulen++;
		}
	}
	for(int i=1;i<=m;i++){
		int v;
		scanf("%d",&v);
		adde(i+n,t,v);
	}
}

void dfs(int u){
    for(int i = head[u];~i;i=e[i].nxt){
    	int v = e[i].v;
    	if(!vis[v]&&e[i].cap>e[i].flow){
    		vis[v]=1;
    		dfs(v);
		} 
	}
}

void print(){
	for(int i=1;i<=n;i++)//dfs，能够从源点沿着cap>flow到达节点都属于S集合 
		if(vis[i]) printf("%d ",i);
	printf("\n");
	for(int j=1;j<=m;j++)
		if(vis[j+n]) printf("%d ",j);
	printf("\n");
}


int main(){
	readin();
	int ans = ISAP(s,t,t+1);
	memset(vis,0,sizeof(vis));
	dfs(s);
	print();
	cout<<sum-ans<<endl;
	return 0;
}
