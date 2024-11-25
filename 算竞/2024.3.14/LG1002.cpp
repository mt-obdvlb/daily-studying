#include<iostream>

using namespace std;

long long bx,by,hx,hy;
long long f[25][25]={0};

long long dir[9][2]{2,1,2,-1,-2,1,-2,-1,
			 1,2,-1,2,1,-2,-1,-2};

long long vis[30][30]={0};

int main(){
	cin>>bx>>by>>hx>>hy;
	bx+=3,by+=3,hx+=3,hy+=3;
	f[2][3]=1;
	for(long long i = 0;i<9;i++)vis[hx+dir[i][0]][hy+dir[i][1]]=1;
	for(long long i = 3;i<=bx;i++){
		for(long long j = 3;j<=by;j++){
			if(vis[i][j])continue;
			f[i][j]=f[i-1][j]+f[i][j-1]; 
		}
	}
	
	cout<<f[bx][by]<<endl;
	
	return 0;
} 
