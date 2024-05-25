#include<bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 410;
const int M = 20500;
int n,cnt,f,d,head[N],pre[N],h[N],g[N];
struct edges{
	int v,nxt,cap,flow;
}e[M<<1];
void add(int u,int v,int w){
	e[cnt].v = v;
	e[cnt].nxt = head[u];
	e[cnt].cap = w;
	e[cnt].flow = 0;
	head[u] = cnt++;
}

void adde(int u,int v,int w){
	add(u,v,w);
	add(v,u,0);
}

void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}

void set_h(int t,int n){
	memset(g,0,sizeof(g));
	memset(h,-1,sizeof(h));
	h[t]=0;
	queue<int>q;
	q.push(t);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		++g[h[u]];
		for(int i = head[u];~i;i=e[i].nxt){
			int v = e[i].v;
			if(h[v]==-1){
				h[v]=h[u]+1;
				q.push(v);
			}
		}
	}
}

int ISAP(int s,int t,int n){
	set_h(t,n);
	int u = s,ans=0,d;
	while(h[s]<n){
		if(u==s)d=inf;
		int i = head[u];
		for(;~i;i = e[i].nxt){
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
			++g[h[u]];
			if(u!=s)u=e[pre[u]^1].v;
		}
	}
	return ans; 
}

int main(){
	cin>>n>>f>>d;
	int s=0,t=f+2*n+d+1;
	init();
	int x,y,k;
	for(int i = 1;i<=f;i++)adde(s,i,1);
	for(int i = 1;i<=n;i++)adde(f+i,f+n+i,1);
	for(int i = 1;i<=d;i++)adde(f+2*n+i,t,1);
	for(int i = 1;i<=n;i++){
		cin>>x>>y;
		for(int j = 1;j<=x;j++){
			cin>>k;
			adde(k,f+i,1);
		}
		for(int j =1;j<=y;j++){
			cin>>k;
			adde(f+n+i,f+2*n+k,1);
		}
	}
	cout<<ISAP(s,t,t+1)<<endl;
	return 0;
}
