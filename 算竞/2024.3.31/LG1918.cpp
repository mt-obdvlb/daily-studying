#include<bits/stdc++.h>

using namespace std;

int main(){
	int t,n,q;
	cin>>n;
	map<int,int> mp;
	for(int i = 1;i<=n;i++){
		scanf("%d",&t);
		mp[t]=i;
	}
	
	cin>>q;
	while(q--){
		scanf("%d",&t);
		if(mp.find(t)==mp.end())printf("0\n");
		else printf("%d\n",mp[t]);
	}
	return 0;
}
