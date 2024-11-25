#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 5e2+5;
ll g[N][N]; 

int n,m,a,b;

bool check(ll x){
	int Cnt = 0,cnt = 0;
	ll tmp = 0;
	int i = 1,k;
	while(i<=n){
		k = i-1;
		cnt = tmp = 0;
		while(i<=n&&cnt<b){
			cnt = 0,tmp = 0;
			for(int j = 1;j<=m;j++){
				tmp+= g[i][j]-g[k][j];
				if(tmp>x){
					tmp = 0;
					cnt++;
				}
			}
			i++;
		}
		if(cnt<b)return false;
		Cnt++;
		if(Cnt>=a)return true; 
	}
	return Cnt>=a;
}

int main(){
	cin>>n>>m>>a>>b;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			scanf("%lld",&g[i][j]);
			g[i][j]+=g[i-1][j];
		}
	}
	ll l = 1,r = 1e18,mid;
	while(l<r){
		mid = (l+r)>>1;
		if(check(mid)){
			l = mid+1;
		}else{
			r = mid;
		}
	}
	cout<<l<<endl;
	return 0;
}
