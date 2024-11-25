#include<bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
const int M = 2e5+10;
int cnt,head[N],pre[N],h[N],g[N];
struct Edges{
	int v,nxt,cap,flow;
}e[M<<1];

void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}

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

void set_h(int t,int n){
	memset(h,-1,sizeof(h));
	memset(g,0,sizeof(g));
	queue<int> q;
	q.push(t);
	h[t]=0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		g[h[u]]++;
		for(int i = head[u];~i;i = e[i].nxt){
			int v = e[i].v;
			if(h[v]==-1){
				h[v] = h[u]+1;
				q.push(v);
			}
		}
	}
}

int ISAP(int s,int t,int n){
	set_h(t,n);
	int ans = 0,u=s,d;
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
						u=e[j^1].v;
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
	int T,n,m,s,t;
    scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int minx=inf;
		int maxx=-inf;
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if(x>maxx){
				maxx=x;
				t=i;
			}
			if(minx>x){
				minx=x;
				s=i;
			}
		}//找到源点和汇点。 
		init();
		while(m--){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			adde(u,v,w);//双向！ 
			adde(v,u,w);//双向！
		}
		printf("%d\n",ISAP(s,t,n));
	} 
	
	return 0;
} 
