#include<iostream>
#include<queue>
#include<algorithm>
#define sq(x) ((x)*(x))
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
typedef long long ll;
const int N = 5e4+10;
int n,k,idx,m,sz[N<<2],top;
struct Node{
	int x[5];
	bool operator<(const Node &b)const{
		return x[idx]<b.x[idx];
	}
	
}a[N];
typedef pair<ll,Node> PLN;
priority_queue<PLN> q;
Node kd[N<<2];

ll getdis(int rt,Node &p){
	ll ret = 0;
	for(int i = 0;i<k;i++)ret+=sq((ll)kd[rt].x[i]-p.x[i]);
	return ret;
}

void build(int rt,int l,int r,int dep){
	if(l>r)return;
	int mid = (l+r)>>1;
	idx=dep%k;
	nth_element(a+l,a+mid,a+r+1);
	kd[rt]=a[mid];
	sz[rt]=1,sz[lc]=sz[rc]=1;
	build(lc,l,mid-1,dep+1);
	build(rc,mid+1,r,dep+1);
}

void query(int rt,int dep,Node &p){
	if(!sz[rt])return;
	idx = dep%k;
	ll dis = getdis(rt,p);
	int flag = 0;
	ll rd = sq((ll)kd[rt].x[idx]-p.x[idx]);
	int l = rt<<1,r = rt<<1|1;
	if(p.x[idx]>=kd[rt].x[idx])swap(l,r);
	query(lc,dep+1,p);
	if(q.size()<m)q.push(PLN(dis,kd[rt])),flag=1;
	else{
		if(q.top().first>dis){
			q.pop();
			q.push(PLN(dis,kd[rt])); 
		}
		if(rd<q.top().first)flag=1;
	}
	if(flag)query(rc,dep+1,p);
}

int main(){
	int t;
	while(~scanf("%d%d",&n,&k)){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<k;j++)scanf("%d",&a[i].x[j]);
		}		
		build(1,0,n-1,0);
		scanf("%d",&t);
		Node p;
		Node st[15];
		while(t--){
			for(int j = 0;j<k;j++)scanf("%d",&p.x[j]);
			scanf("%d",&m);
			query(1,0,p);			
			for(top = 1;!q.empty();q.pop()){
				st[top++] = q.top().second;
			}
			printf("the closest %d points are:\n",m);
			while(--top){
				for(int i = 0;i<k;i++){
					if(i)printf(" ");
					printf("%d",st[top].x[i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
