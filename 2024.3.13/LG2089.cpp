#include<iostream>

using namespace std;

int n;
int cnt = 0;
int ans[100000][10];
int arr[10];

void dfs(int w,int ind){
	if(w>n)return;
	if(ind==10){
		if(n!=w)return;
		for(int i = 0;i<n;i++)ans[cnt][i]=arr[i];
		cnt++;
		return;
	}
	for(int i = 1;i<=3;i++){
		arr[ind]=i;
		dfs(w+i,ind+1);
	}
}

int main(){
	cin>>n;
	dfs(0,0);
	cout<<cnt<<endl;
	for(int i = 0;i<cnt;i++){
		for(int j = 0;j<10;j++){
			if(j)printf(" ");
			printf("%d",ans[i][j]);
		}
		cout<<endl;
	}
	return 0;
}
