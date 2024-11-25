#include<iostream>

using namespace std;

int n;

int st[(1<<8)+5][(1<<8)+5];


int main(){
	cin>>n;
	for(int i = 1;i<=(1<<n);i++)scanf("%d",&st[i][0]);
	for(int j = 1;j<=n;j++){
		for(int i = 1;i<=(1<<n);i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}	
	int t = min(st[1][n-1],st[1+(1<<(n-1))][n-1]);
	for(int i = 1;i<=(1<<n);i++){
		if(t==st[i][0]){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
