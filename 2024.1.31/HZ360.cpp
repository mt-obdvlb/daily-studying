#include<iostream>


using namespace std;

#define INF 0x3f3f3f3f

int n;
int val[10][10]={0};
int dp[20][10][10][10][10]={0};

int S(int x){
	return x*x;
}

int Val(int i,int j,int k,int l){
	return val[k][l] +val[i-1][j-1] -val[i-1][l]-val[k][j-1];
} 

int main(){
	cin>>n;	
	for(int i = 1;i<=8;i++){
		for(int j = 1;j<=8;j++){
			scanf("%d",&val[i][j]);
			val[i][j]+=val[i-1][j]+val[i][j-1]-val[i-1][j-1];
		}
	}
	for(int i = 1;i<=8;i++){
		for(int j = 1;j<=8;j++){
			for(int k = i;k<=8;k++){
				for(int l = j;l<=8;l++){
					dp[1][i][j][k][l] = S(Val(i,j,k,l));
				}
			}
		}
	}
	for(int t = 2;t<=n;t++){
		for(int i = 1;i<=8;i++){
			for(int j = 1;j<=8;j++){
				for(int k = i;k<=8;k++){
					for(int l = j;l<=8;l++){
						int ans = INF;
						for(int c = i;c<k;c++){
							int val1 = dp[1][i][j][c][l]+dp[t-1][c+1][j][k][l];
							int val2 = dp[t-1][i][j][c][l]+dp[1][c+1][j][k][l];
							ans = min(ans,min(val1,val2));							
						} 
						for(int c = j;c<l;c++){
							int val1 = dp[1][i][j][k][c]+dp[t-1][i][c+1][k][l];
							int val2 = dp[t-1][i][j][k][c]+dp[1][i][c+1][k][l];
							ans = min(ans,min(val1,val2));
						}
						dp[t][i][j][k][l] = ans;
					}
				}
			}
		}	
	}
	cout<<dp[n][1][1][8][8]<<endl;
	return 0;
}
