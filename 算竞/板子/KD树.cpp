#include<iostream>
#include<algorithm>
#define S(x) (x)*(x)
using namespace std;
typedef long long ll;
const int N=100010;
const ll inf=1e18;
int idx,k=2;
ll ans;
struct Node{
	int x[2];
	bool operator<(const Node &b)const{
		return x[idx]<b.x[idx];
	}
}a[N],p[N];

ll getdis(Node &p,Node &q){
	ll res = 0;
	for(int i = 0;i<k;i++)
		res += S((ll)p.x[i]-q.x[i]);
	return res?res:inf;
}

void build(int l,int r,int dep){
	if(l>r)return;
	int mid = (l+r)>>1;
	idx = dep % k;
	nth_element(a + l,a + mid,a + r + 1);
	build(l,mid-1,dep+1);
	build(mid+1,r,dep+1); 
}

void query(int l,int r,int dep,Node &p){
	if(l>r)return;
	int mid = (l+r)>>1,dim = dep % k;
	ll dis = getdis(a[mid],p);
	if(dis<=ans)ans = dis;
	ll rd = S((ll)a[mid].x[dim]-p.x[dim]);
	if(p.x[dim]<a[mid].x[dim]){
		query(l,mid-1,dep+1,p);
		if(rd<ans)
			query(mid+1,r,dep+1,p);
	} else{
		query(mid+1,r,dep+1,p);
		if(rd<ans)
			query(l,mid-1,dep+1,p);
	}
}

int main(){
	
	
	return 0;
}
