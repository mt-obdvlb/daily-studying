#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
typedef long long ll;
ll T,n,a[N][20];
int k,lb[N];

void init(){
	lb[0] = -1;
	for(int i = 1;i<N;i++){
		lb[i] = ((i&(i-1))?lb[i-1]:lb[i-1]+1);
	}
}

ll get(int l,int r){
	return a[l][k]|a[r-(1<<k)+1][k];
}

bool check(int x){
	k = lb[x];
	for(int i = 2;i<=n-x+1;i++){
		if(get(i,i+x-1)!=get(i-1,i+x-2)){
			return false;
		}
	}
	return true;
}

int main(){
	cin>>T;
	init();
	while(T--){
		scanf("%lld",&n);
		for(int i = 1;i<=n;i++)scanf("%lld",&a[i][0]);
		k = lb[n];
		for(int j = 1;j<=k;j++){
			for(int i = 1;i<=n-(1<<j)+1;i++){
				a[i][j] = a[i][j-1]|a[i+1<<(j-1)][j-1];
			}
		}
		int l = 1,r = n,mid,ans;
		while(l<r){
			mid = (l+r)>>1;
			if(check(mid)){
				ans=mid;
				r = mid;
			}else{
				l = mid+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
