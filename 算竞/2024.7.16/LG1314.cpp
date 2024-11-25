#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5+10;
const ll inf = 1e18;
int n,m;
ll s;
ll w[N],v[N],cnt[N],a[N],b[N];
struct Data{
	int l,r;
}p[N];

ll check(ll x){
	ll res = 0;
	for(int i = 1;i<=n;i++){
		a[i]=a[i-1];
		b[i]=b[i-1]; 
		if(w[i]>=x){
			a[i]+=v[i];
			b[i]++;
		}
	}

	for(int i = 1;i<=m;i++){
		res+=(a[p[i].r]-a[p[i].l-1])*(b[p[i].r]-b[p[i].l-1]);
	}
	return res;
}

int main(){
	cin>>n>>m>>s;
	ll l = 0,r = 0,mid,ans = inf;
	for(int i = 1;i<=n;i++){
		scanf("%d%d",w+i,v+i);
		r = max(r,(ll)w[i]);
	}
	int a,b;
	for(int i = 1;i<=m;i++){
		scanf("%d%d",&p[i].l,&p[i].r);
	}
	for(int i = 1;i<=n;i++)cnt[i]+=cnt[i-1];
	while(l<=r){
		mid = (l+r)>>1;
		ll x = check(mid);
		ans = min(ans,abs(x-s));
		if(x>s){
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
