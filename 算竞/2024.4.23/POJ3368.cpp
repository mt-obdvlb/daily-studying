#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int n,q,l,r,cnt,t,st[100005][32],a[100005],lb[100005];

int RMQ(int l,int r){
	if(l>r)return 0;
	int k = lb[r-l+1];
	return max(st[l][k],st[r-(1<<k)+1][k]);
}

int main(){
	lb[0] = -1;
	for(int i = 1;i<100005;i++)
		lb[i] = (i&(i-1))?lb[i-1]:lb[i-1]+1; 
	while(cin>>n&&n&&cin>>q){
		a[0]= INF;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
			if(i==1)st[i][0]=1;
			if(a[i]==a[i-1])st[i][0] = st[i-1][0]+1;
			else st[i][0] = 1;
		}
		for(int j = 1;j<=lb[n];j++){
			for(int i = 1;i<=n+1-(1<<j);i++)
				st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}	
		while(q--){
			cin>>l>>r;
			int t = l;
			while(t<=r&&a[t]==a[t-1])t++;
			cout<<max(t-l,RMQ(t,r))<<endl;
		}	
	}
	return 0;
}
