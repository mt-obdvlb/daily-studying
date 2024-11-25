#include<bits/stdc++.h>

using namespace std;
const int N = 1e3+5;
int g[N][N];

int n,m,c;

int main(){
	cin>>n>>m>>c;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			scanf("%d",&g[i][j]);
			g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
		}
	}
	int ans = -0x3f3f3f3f;
	int x,y;
	for(int i = c;i<=n;i++){
		for(int j = c;j<=m;j++){
			if(ans<g[i][j]-g[i-c][j]-g[i][j-c]+g[i-c][j-c]){
				x = i-c+1,y = j-c+1;
				ans = g[i][j]-g[i-c][j]-g[i][j-c]+g[i-c][j-c];
			}
		}
	}
	printf("%d %d\n",x,y);
	return 0;
}
