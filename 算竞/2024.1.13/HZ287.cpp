#include<bits/stdc++.h>

using namespace std;

int find_min(vector<int> &v,int n){
	int min_index = 0,min = 0x3f3f3f3f; 
	for(int i = 0;i<n;i++){
		if(v[i]<min){
			min = v[i];
			min_index = i;
		}
	}
	swap(v[n-1],v[min_index]);
	v.pop_back();
	return min;
}

int main(){
	int n,sum = 0;
	cin>>n;
	vector<int> v;
	v.resize(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	for(int i =1;i<n;i++){
		int min = 0;
		int a = find_min(v,n-i+1);
		int b = find_min(v,n-i);
		int tmp_sum = a + b;
		v.push_back(tmp_sum);
		sum+=tmp_sum;
	}
	cout<<sum;
	return 0;
}
