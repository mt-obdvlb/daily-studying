#include<iostream>
#include<cstdio>

using namespace std;

typedef long long ll;

ll a,b,c;

ll f[25][25][25];

ll w(ll a,ll b,ll c){
	if(a<=0||b<=0||c<=0)return 1;
	if(a>20||b>20||c>20){
		a=20,b=20,c=20;
	}
	for(int i = 0;i<=a;i++)f[i][0][0]=1;
	for(int i = 0;i<=b;i++)f[0][i][0]=1;
	for(int i = 0;i<=c;i++)f[0][0][i]=1;
	for(int i = 0;i<=a;i++){
		for(int j =0;j<=b;j++)f[i][j][0]=1;
	}
	for(int i = 0;i<=b;i++){
		for(int j =0;j<=c;j++)f[0][i][j]=1;
	}
	for(int i = 0;i<=a;i++){
		for(int j =0;j<=c;j++)f[i][0][j]=1;
	}
	f[0][0][0]=1;
	for(int i = 1;i<=a;i++){
		for(int j = 1;j<=b;j++){
			for(int k =1;k<=c;k++){
				if(i<j&&j<k){
					f[i][j][k]=f[i][j][k-1]+f[i][j-1][k-1]-f[i][j-1][k];
				}else{
					f[i][j][k]=f[i-1][j][k]+f[i-1][j-1][k]+
							f[i-1][j][k-1]-f[i-1][j-1][k-1];
				}
			}
		}
	}
	
	return f[a][b][c];
}

int main(){
	while(~scanf("%lld%lld%lld",&a,&b,&c)){
		if(a==-1&&b==-1&&c==-1)break;
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
	}
	return 0;
}
