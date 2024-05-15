#include<bits/stdc++.h>
#define lc t[x].l
#define rc t[x].r
using namespace std;
const int N = 2e4+5;
int n,cnt_tr,a[N],b[N],rt[N],num[N];
struct LeftTree{
	int l,r,sz,key,dis;
}t[N];

int getnewtree(int x){
	t[++cnt_tr].key=x;
	t[cnt_tr].l=t[cnt_tr].r=t[cnt_tr].dis=0;
	t[cnt_tr].sz=1;
	return cnt_tr;
}

int merge(int x,int y){
	if(!x||!y)return x|y;
	if(t[x].key<t[y].key)swap(x,y);
	rc = merge(rc,y);
	if(t[lc].dis<t[rc].dis)swap(lc,rc);
	t[x].dis = t[rc].dis+1;
	t[x].sz = t[lc].sz+t[rc].sz+1;
	return x;
}

void del(int &x){
	x=merge(lc,rc);
}

int solve(int a[]){
	int cnt = 0,ans =0;
	cnt_tr = 0;
	for(int i = 0;i<n;i++){
		rt[++cnt]=getnewtree(a[i]);
		num[cnt]=1;
		while(cnt>1&&t[rt[cnt]].key<t[rt[cnt-1]].key){
			cnt--;
			rt[cnt] = merge(rt[cnt],rt[cnt+1]);
			num[cnt]+=num[cnt+1];
			if(t[rt[cnt]].sz*2>num[cnt]+1)del(rt[cnt]);
		}
	}
	int k = 0;
	for(int i = 1;i<=cnt;i++){
		for(int j = 0,x=t[rt[i]].key;j<num[i];j++){
			ans+=abs(a[k++]-x);
		}
	}
	return ans;
}

int main(){
	while(~scanf("%d",&n)){
		for(int i = 0;i<n;i++){
			scanf("%d",&a[i]),b[n-i-1]=a[i];
		}
		printf("%d\n",min(solve(a),solve(b)));
	}
	return 0;	
}
