#include<iostream>
#include<algorithm>
using namespace std;

int m,n,ans=0;
int t[505],c[505],ind[505];
int vis[505]={0};

typedef pair<int,int> PII; 

int main(){
	cin>>m>>n;
	for(int i = 1;i<=n;i++){
		scanf("%d",t+i);
		ind[i]=i;
	}
	for(int i = 1;i<=n;i++){
		scanf("%d",c+i);
	}
	sort(ind+1,ind+1+n,[&](int i,int j)->bool{
		return c[i]>c[j];
	});
	for(int i = 1;i<=n;i++){
		int flag = 1;
		for(int j = t[ind[i]];flag&&j>=1;j--){
			if(vis[j])continue;
			vis[j]=1;
			flag=0;
		}
		if(flag)ans+=c[ind[i]];
	}
	cout<<(m>ans?m-ans:0)<<endl;
	return 0;
}
