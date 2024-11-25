#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+10;
int n,m; 
int d[N][N];

int main(){
	int x1,x2,y1,y2;
	cin>>n>>m; 
	while(m--){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		d[x1][y1]++;
		d[x2+1][y2+1]++;
		d[x1][y2+1]--;
		d[x2+1][y1]--;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];
			printf("%d ",d[i][j]);
		}
		cout<<endl;
	}
	return 0;
}
