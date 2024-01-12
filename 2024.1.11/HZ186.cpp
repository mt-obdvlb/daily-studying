#include<bits/stdc++.h>

using namespace std;

int Count = 0;

void f(int i,int n,int* nums){
	if(i>n){
		return;
	}
	Count++;
	f(i + nums[i],n,nums);
}


int main(){
	int n;
	cin>>n;
	int* nums = new int[n+1];
	for(int i = 0;i<n;i++){
		cin>>nums[i+1];
	}
	f(1,n,nums);
	cout<< Count <<endl;
	delete nums;
	return 0;
}
