#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1e5+5;
int T,n,m,h,a[N];
int L[N],R[N],ind[N],tmp[N];

void build(){
	int t = sqrt(n);
	int num = n/t;
	if(n%t)num++;
	for(int i = 1;i<=num;i++){
		L[i] = (i-1)*t+1;
		R[i] = i*t;
	}
	R[num] = n;
	for(int i = 1;i<=n;i++){
		ind[i] = (i-1)/t+1;
	}
	for(int i = 1;i<=num;i++){
		sort(tmp+L[i],tmp+R[i]+1);
	}
}

int query(int l,int r){
	int tot = 0;
	int p = ind[l],q = ind[r];
	if(p==q){
		for(int i = l;i<=r;i++){
			if(h>=a[i])tot++;			
		}
		return tot;
	}
	for(int i = p+1;i<=q-1;i++){
		tot+=upper_bound(tmp+L[i],tmp+R[i]+1,h)-tmp-L[i];
	}
	for(int i = l;i<=R[p];i++){
		if(h>=a[i])tot++;			
	}
	for(int i = L[q];i<=r;i++){
		if(h>=a[i])tot++;			
	}
	return tot;
}

int read(){
	int ret = 0;
	char ch;
	ch = getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		ret = ret*10+ch-'0';
		ch = getchar();
	}	
	return ret;
}

void solve(){
	n =read(),m = read();
	for(int i = 1;i<=n;i++){
		a[i] =read();		
		tmp[i]=a[i]; 
	}
	build();	
	int l,r;
	while(m--){
		l = read(),r =read(),h = read();
		printf("%d\n",query(l+1,r+1));
	}
}

int main(){
	T=read();
	for(int i = 1;i<=T;i++){
		printf("Case %d:\n",i);
		solve();		
	}
	return 0;
}
