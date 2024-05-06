#include<bits/stdc++.h>

using namespace std;

int n,b,k,t,st1[255][255][32],st2[255][255][32];

int main(){
	cin>>n>>b>>k;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			scanf("%d",&t);
			st1[i][j][0] = st2[i][j][0] = t;
		}
	}
	for(int i = 1;i<=n;i++){
		for(int k = 1;k<=log2(n);k++){
			for(int j = 1;j<=n-(1<<(k))+1;j++){
				st1[i][j][k] = max(st1[i][j][k-1],st1[i][j+(1<<(k-1))][k-1]);
				st2[i][j][k] = min(st2[i][j][k-1],st2[i][j+(1<<(k-1))][k-1]);
			}
		}
	}
	t = log2(b);
	cout<<t<<endl;
	int i,j,maxx = -1,minx = 25555555;
	while(k--){
		scanf("%d%d",&i,&j);
		for(int l = 0;l<b;l++){
			maxx = max(maxx,max(st1[i+l][j][t],st1[i+l][j+b-1-(1<<(t))+1][t]));
			minx = min(minx,min(st2[i+l][j][t],st2[i+l][j+b-1-(1<<(t))+1][t]));
		}
		cout<<maxx-minx<<endl;
	}
	return 0;
}
