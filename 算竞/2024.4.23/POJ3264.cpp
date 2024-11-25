#include<bits/stdc++.h>

using namespace std;

int n,q,st1[50005][32],st2[50005][32],l,r;


int main(){
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>st1[i][0];
		st2[i][0]=st1[i][0];
	}
	int k = log2(n);
	for(int j = 1;j<=k;j++){
		for(int i = 1;i<=n-(1<<j)+1;i++){
			st1[i][j] =max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
			st2[i][j] =min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
		}
	}	
	while(q--){
		cin>>l>>r;
		k = log2(r-l+1);
		cout<<max(st1[l][k],st1[r-(1<<k)+1][k])-min(st2[l][k],st2[r-(1<<k)+1][k])<<endl;
	}
	return 0;
}
