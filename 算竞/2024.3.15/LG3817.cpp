#include<iostream>

using namespace std;

long long arr[100005];

int main(){
	int n,x;
	cin>>n>>x;
	long long ans = 0;
	for(int i =0;i<n;i++){
		scanf("%lld",arr+i);
	}
	for(int i = 1;i<n;i++){
		if(arr[i-1]+arr[i]>x){
			ans += arr[i-1]+arr[i]-x;
			arr[i]-=arr[i-1]+arr[i]-x;
			if(arr[i]<0){
				int t = -arr[i];
				arr[i-1]-=t;
				arr[i]=0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
