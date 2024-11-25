#include<iostream>
#include<string>
using namespace std;

int vis[12][12][4][12][12][4]={0};
int dir[4][2]={-1,0,0,1,
				1,0,0,-1
				};
char board[12][12];



int ans = 0; 


void dfs(int ci,int cj,int fi,int fj,int dirc,int dirf,int t){
	if(ci==fi&&cj==fj){
		ans = t;
		return;
	}
	if(vis[ci][cj][dirc][fi][fj][dirf])return;
	vis[ci][cj][dirc][fi][fj][dirf]=1;
	if(board[ci+dir[dirc][0]][cj+dir[dirc][1]]=='*'){
		dirc=(dirc+1)%4;
	}else{
		ci+=dir[dirc][0];
		cj+=dir[dirc][1];
	}
	if(board[fi+dir[dirf][0]][fj+dir[dirf][1]]=='*'){
		dirf=(dirf+1)%4;
		
	}else{
		fi+=dir[dirf][0];
		fj+=dir[dirf][1];
	}
	dfs(ci,cj,fi,fj,dirc,dirf,t+1);
}


int main(){
	int fi,fj,ci,cj;
	for(int i = 0;i<=11;i++){
		for(int j = 0;j<=11;j++){
			board[i][j]='*';
		}
	}
	for(int i = 1;i<=10;i++){
		string s;
		cin>>s;
		for(int j = 0;j<10;j++){
			if(s[j]=='C'){
				ci=i,cj=j+1;
			}
			if(s[j]=='F'){
				fi=i,fj=j+1;
			}
			board[i][j+1]=s[j];
		}
	}
	
	dfs(ci,cj,fi,fj,0,0,0);
	cout<<ans<<endl;
	return 0;
}
