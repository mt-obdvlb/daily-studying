#include<algorithm>
#include<iostream>

using namespace std;

int n,Sum = 0;
int arr[100005];

int main(){
	cin>>n;
	for(int i =0;i<n;i++){
		scanf("%d",arr+i);
		Sum+=arr[i];
	}
	sort(arr,arr+n);
	int g = arr[n/2];
	int ans = 0;
	for(int i = 0;i<n;i++){
		if(arr[i]>=g)ans++;
	}
	cout<<g<<" "<<ans<<endl;
	return 0;
}
