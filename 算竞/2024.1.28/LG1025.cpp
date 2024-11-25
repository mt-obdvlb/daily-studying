#include<iostream>


using namespace std;

int f[205][10]={0};

int main(){
	int n,k;
	cin>>n>>k;
	f[0][0]=f[1][1]=1;
	for(int i = 1;i<=n;i++){
		f[i][1]=f[i][i]=1;
		for(int j = 2,J=min(i,k);j<=J;j++){
			f[i][j] = f[i-1][j-1] + f[i-j][j];
		}
	}
	cout<<f[n][k]<<endl;
	return 0;
}
