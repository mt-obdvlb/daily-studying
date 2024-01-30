#include<iostream>


using namespace std;

int f[35][36];

int main(){
	int n,m;
	cin>>n>>m;
	f[0][1] = 1;
	for(int j = 1;j<=m;j++){
		for(int i = 1;i<=n;i++){
			f[j][i] = f[j-1][i-1]+f[j-1][i+1];
			if(i==1)f[j][i] += f[j-1][n];
			if(i==n)f[j][i] += f[j-1][1];
		}
	}
	cout<<f[m][1]<<endl;
	return 0;
}
