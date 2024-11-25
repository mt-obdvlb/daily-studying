#include<bits/stdc++.h>

using namespace std;

int n;
int arr[30005];
int dp[30005];

int main(){
	cin>>n;
	for(int i = 1;i<=n;i++)scanf("%d",arr+i);
	deque<int> d;
	d.push_back(n);
	int ans = 0;
	for(int i = n-1;i>=1;i--){
		while(!d.empty()&&arr[i]>=arr[d.back()])d.pop_back();
		if(!d.empty()){
			int M = arr[d.back()],MM=arr[d.front()];
			if(MM>M)ans+=d.size();
		}
		d.push_back(i);
	}
	cout<<ans<<endl;
	return 0;
}
