#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

map<long long,long long> m;
long long n,c;
long long arr[200005];

int main(){
	cin>>n>>c;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i = 0;i<n;i++){
		++m[arr[i]];
	}
	long long cnt = 0;
	for(int i = 0;i<n;i+=m[arr[i]]){
		long long pos = lower_bound(arr+i+m[arr[i]],arr+n,c+arr[i])-arr;
		if(arr[pos]==c+arr[i])cnt+=m[arr[i]]*m[arr[pos]];
	}
	cout<<cnt<<endl;
	return 0;
}
