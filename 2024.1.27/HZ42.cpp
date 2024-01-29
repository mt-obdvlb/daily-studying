#include<iostream>



using namespace std;

int mon[25];
int f[25][10005];

int main(){
	int m,n;
	cin>>m>>n;
	for(int i = 1;i<=m;i++){
		cin>>mon[i];
	}
	for(int i = 1;i<=m;i++){
		f[i][0] = 1;
		for(int j = 1;j<=n;j++){
			f[i][j] = f[i-1][j];	
			if(j<mon[i])continue;
			f[i][j] += f[i][j-mon[i]];
			f[i][j]%=9973;
		}
	}
	cout<<f[m][n]<<endl;
	
	return 0;
}
