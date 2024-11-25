#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 1e8+5;
int n,q,tot;
ll prime[6000010];
bool vis[N];

void build(){
	for(int i = 2;i<=n;i++){
		if(!vis[i])prime[++tot]=i;
		for(int j = 1;j<=tot&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}

int main(){
	scanf("%d%d",&n,&q);
	build();
	int ind;
	while(q--){
		scanf("%d",&ind);
		printf("%lld\n",prime[ind]);	
	}
	return 0;
}
