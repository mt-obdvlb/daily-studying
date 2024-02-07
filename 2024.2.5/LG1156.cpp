#include<bits/stdc++.h>


using namespace std;

int D,G,H = 0;

struct Data{
	int t,f,h;
}arr[105];

int dp[205];

int main(){
	cin>>D>>G;
	for(int i = 1;i<=G;i++){
		cin>>arr[i].t>>arr[i].f>>arr[i].h;
	}
	sort(arr+1,arr+1+G,[&](const Data &a,const Data &b)->bool{
		return a.t<b.t;
	});
	dp[0]=10;
	for(int i = 1;i<=G;i++){
		for(int j = D;j>=0;j--){
			if(dp[j]<arr[i].t)continue;
			if(j+arr[i].h>=D){
				cout<<arr[i].t<<endl;
				return 0; 
			}
			dp[j+arr[i].h]=max(dp[j+arr[i].h],dp[j]);
			dp[j]+=arr[i].f;
		}
	}
	cout<<dp[0]<<endl;
	return 0;
}
