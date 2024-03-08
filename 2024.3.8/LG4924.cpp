#include<iostream>

using namespace std;

int n,m;
int board[505][505];

int main(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			board[i][j]=(i-1)*n+j;
		}
	}
	for(int x,y,r,z,i = 0;i<m;i++){
		scanf("%d%d%d%d",&x,&y,&r,&z);
		int tmp[505][505]={0};
		for(int i = x-r;i<=x+r;i++){
			for(int j = y-r;j<=y+r;j++){
				if(z==0)tmp[x-r+j-y+r][y+r+x-r-i]=board[i][j];
				else tmp[x+r+y-r-j][y-r+i-x+r]=board[i][j];
			}
		}
		for(int i = x-r;i<=x+r;i++){
			for(int j = y-r;j<=y+r;j++){
				board[i][j]=tmp[i][j];
			}
		}
		
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(j!=1)printf(" ");
			printf("%d",board[i][j]); 
		}
		printf("\n");
	}
	return 0;
}
