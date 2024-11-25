#include<iostream>
#include<cinttypes>
using namespace std;

int n;
int vis[15]={0};
int x[15]={0},y[15]={0};
int arr[15][15]={0};

int main(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i = 0;i<=n;i++){
		for(int j = 0;j<=n;j++){
			arr[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
		}
		arr[i][i]=INT32_MAX;
	}
	vis[0]=1;
	int ans=0;
	for(int i = 0;i<=n;i++){
		int ind = i;
		for(int j = 0;j<=n;j++){
			if(vis[j])continue;
			if(arr[i][j]<arr[i][ind])ind=j;
		}
		ans+=min(arr[i][ind],arr[0][ind]);
		vis[ind]=1;
	}
	cout<<ans<<endl;
	return 0;
}
