#include<iostream>
#include<vector>


using namespace std;

int val[1005][1005];
int f[1005][1005];


int main(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=i;j++){
			scanf("%d",val[i]+j);
		}
	}
	for(int i = 1;i<=n;i++)f[n][i] = val[n][i];
	for(int i = n-1;i>=1;i--){
		for(int j = 1;j<=i;j++){
			f[i][j] = max(f[i+1][j],f[i+1][j+1])+val[i][j];
		}
	}
	cout<<f[1][1]<<endl;
	return 0;
} 
