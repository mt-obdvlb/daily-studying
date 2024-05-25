#include<bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1010;
const int M = 1e6+100;
int T,n,m,d,cnt,head[N],pre[N],h[N],g[N];

struct{
	int v,nxt,flow,cap;
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

void set_h(int t,int n){
	queue<int>q;
	memset(h,-1,sizeof(h));
	memset(g,0,sizeof(g));
	q.push(t);
	h[t]=0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		g[h[u]]++;
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
	int ans=0,d,u=s;
	while(h[s]<n){
		int i = head[u];
		if(u==s)d=inf;
		for(;~i;i=e[i].nxt){
			int v = e[i].v;
			if(e[i].cap>e[i].flow&&h[u]==h[v]+1){
				pre[v]=i;
				u=v;
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
			int dmin = n-1;
			for(int j = head[u];~j;j=e[j].nxt){
				if(e[j].cap>e[j].flow)
					dmin=min(dmin,h[e[j].v]);
			}
			h[u]=dmin+1;
			g[h[u]]++;
			if(s!=u)u=e[pre[u]^1].v;
		}
	}
	return ans;
}

void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}

int main(){
	cin>>T;
	string s;
	int st,t,sum=0;
	for(int tt = 1;tt<=T;tt++){
		sum=0;
		cin>>n>>d;
		for(int i = 0;i<n;i++){
			cin>>s;
			if(i==0){
				m=s.size();
				st=0,t=2*n*m+1;
				init();
			}
			for(int j = 0;j<m;j++){
				if(s[j]-'0'>0){
					int id = i*m+j+1;
					adde(id,id+n*m,s[j]-'0');
					if(i<d||i+d>=n||j<d||j+d>=m)adde(id+n*m,t,inf);
					else{
						for(int k = 0;k<n;k++){
							for(int h = 0;h<m;h++){
								int id2=k*n+h+1;
								if(id==id2)continue;
								if(abs(i-k)+abs(j-h)<=d)adde(id+n*m,id2,inf);
							}
						}
					}
				}
			}
		}		
		for(int i = 0;i<n;i++){
			cin>>s;
			for(int j = 0;j<m;j++){
				int id = i*m+j+1;
				if(s[j]=='L'){
					++sum;
					adde(st,id,1);
				}
			}
		} 
		int ans=sum-ISAP(st,t,t+1);
        if(ans==0) printf("Case #%d: no lizard was left behind.\n",tt);
        else if(ans==1) printf("Case #%d: 1 lizard was left behind.\n",tt);
        else printf("Case #%d: %d lizards were left behind.\n",tt,ans);
	}
	return 0;
}
