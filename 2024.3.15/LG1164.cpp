#include<iostream>

using namespace std;

int n,m;
int f[2][10005];

int main(){
	cin>>n>>m;
	int t;
	cin>>t;
	for(int i = 1;i<=n;i++)f[i%2][0]=1;
	for(int i = 1;i<=m;i++)f[1%2][i]=0;
	f[1%2][t]=1;
	
	for(int i = 2,a;i<=n;i++){
		cin>>a;
		for(int j = 1;j<=m;j++){
			f[i%2][j]=f[(i-1)%2][j];
			if(j-a>=0)f[i%2][j]+=f[(i-1)%2][j-a];
		}
	}
	cout<<f[n%2][m]<<endl;
	return 0;
}
