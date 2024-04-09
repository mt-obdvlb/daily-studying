#include<bits/stdc++.h>

using namespace std;

int n,m,k,ti,tj,g[305][305];

bool check(){
	for(int i = 0;i<m;i++){
		for(int j = 0;j<m;j++){
			int f1 = 0,f2 = 0;
			for(int k = 0;k<m;k++){
				if(g[i][k]&&g[j][k])f1 = 1;
				if(g[i][k]^g[j][k])f2 = 1;
			}
			if(f1&&f2)return false;
		}
	}
	return true;
}

int main(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		scanf("%d%d",&m,&k);
		memset(g,0,sizeof(g));
		for(int j = 0;j<k;j++){
			scanf("%d%d",&ti,&tj);
			g[ti][tj]=1;
		}
		printf("Case #%d: ",i);
		if(check())printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
