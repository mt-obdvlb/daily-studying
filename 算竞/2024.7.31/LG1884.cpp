#include<bits/stdc++.h>
#define lc k<<1
#define rc k<<1|1
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int v[N];
ll ans = 0;

struct segment_tree{
	int l,r,cov;
	ll len;
}t[N<<3]; 

struct line{
	line(){
	}
	line(int x,int y1,int y2,int flag):x(x),y1(y1),y2(y2),flag(flag){}
	int x,y1,y2,flag;
	
	bool operator<(const line& b)const{
		return x<b.x;
	}

}l[N];

void pushup(int k){
	if(t[k].cov)t[k].len = t[k].r - t[k].l;
	else t[k].len = t[lc].len + t[rc].len;
}

void build(int l,int r,int k = 1){
	t[k].l = v[l],t[k].r = v[r];
	if(r-l<=1)return;
	int mid = (l+r)>>1;
	build(l,mid,lc);
	build(mid,r,rc);
}

void modify(int L,int R,int c,int k = 1){
	int l = t[k].l,r = t[k].r;
	if(L<=l&&R>=r){
		t[k].cov+=c;
		pushup(k);
		return;
	}
	if(L<t[lc].r)modify(L,R,c,lc);
	if(R>t[rc].l)modify(L,R,c,rc);
	pushup(k);
}

int main(){
	int n;
	cin>>n;
	int x1,x2,y1,y2;
	for(int i = 1;i<=n;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1>x2)swap(x1,x2);
		if(y1>y2)swap(y1,y2);
		v[i]=y1,v[i+n]=y2;
		l[i] = line(x1,y1,y2,1),l[i+n]=line(x2,y1,y2,-1);
	}
	sort(v+1,v+1+(n<<1));
	sort(l+1,l+1+(n<<1));
	build(1,n<<1); 
	for(int i = 1;i<=n<<1;i++){
		ans += t[1].len*(l[i].x-l[i-1].x);
		modify(l[i].y1,l[i].y2,l[i].flag);
	}
	cout<<ans<<endl;
	return 0;
}
