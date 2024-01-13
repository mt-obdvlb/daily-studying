#include<bits/stdc++.h>

using namespace std;

int main(){
	int storage,n,sum = 0;
	cin>>n;
	vector<int> v;
	v.resize(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	storage = v[n/2];
	for(int i = 0;i<n;i++){
		sum += abs(storage-v[i]);
	}
	cout<<sum<<endl;
	return 0;
}
