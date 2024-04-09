#include<iostream>
#include<bitset>

using namespace std;

int ans=0,n,m,tx,ty;
bitset<1005> bs[1005];


int main(){
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		scanf("%d%d",&tx,&ty);
		bs[tx][ty] = 1;
	}
	
	for(int i = 1;i<=n;i++){
		bs[i][i]=1;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(bs[j][i])bs[j]|=bs[i];
		}
	} 
	for(int i = 1;i<=n;i++)ans+=bs[i].count(); 
	cout<<n*(n-1)/2-ans+n<<endl;
	return 0;
}
