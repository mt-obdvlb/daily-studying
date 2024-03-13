#include<iostream>

using namespace std;

bool flag = true;
int a,b,c;
int arr[9];
int vis[15];

void dfs(int ind){
	if(ind == 9){
		int A = arr[0]*100+arr[1]*10+arr[2];
		int B = arr[3+0]*100+arr[3+1]*10+arr[3+2];
		int C = arr[6+0]*100+arr[6+1]*10+arr[6+2];		
		if(A*b*c==B*a*c&&A*b*c==C*a*b){
			cout<<A<<" "<<B<<" "<<C<<endl;
			flag = false;
		}
	}
	for(int i = 1;i<10;i++){
		if(vis[i])continue;
		vis[i]=1;
		arr[ind]=i;
		dfs(ind+1);
		vis[i]=0;
	}
}

int main(){
	cin>>a>>b>>c;
	dfs(0);
	if(flag)cout<<"No!!!"<<endl;
	return 0;
}
