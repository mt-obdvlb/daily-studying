#include<bits/stdc++.h>

using namespace std;
const int inf=0x3f3f3f3f;
const int N=20010;
const int M=240100;
int cnt,n,m;
int head[N],g[N],pre[N],h[N];
struct Edges{
   int v,nxt;
   int cap,flow;
}e[M<<1];//Ë«±ß



void set_h(int t){
	memset(h,-1,sizeof(h));
	memset(g,0,sizeof(g));
	queue<int>q;
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
	int u=s,d,ans=0;
	while(h[s]<n){
		int i = head[u];
		if(s==u)d=inf;
		for(;~i;i=e[i].nxt){
			int v = e[i].v;
			if(e[i].cap>e[i].flow&&h[u]==h[v]+1){
				u=v;
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
			for(int j  =head[u];~j;j=e[j].nxt){
				if(e[j].cap>e[j].flow)
					hmin=min(hmin,h[e[j].v]);
			}
			h[u]=hmin+1;
			g[h[u]]++;
			if(u!=s)u=e[pre[u]^1].v;
		}
	}
	return ans;
}

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

int main(){
	int a,b,n,m,s,t,w;
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	s=0,t=n+1;
	for(int i = 1;i<=n;i++){
		cin>>a>>b;
		adde(i,t,a);
		adde(s,i,b);
	}
	for(int i = 1;i<=m;i++){
		cin>>a>>b>>w;
		add(a,b,w);
		add(b,a,w);
	}
	cout<<ISAP(s,t,n+2)<<endl;
	return 0;
}
