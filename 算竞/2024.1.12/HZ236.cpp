#include<bits/stdc++.h>

using namespace std;

void _print(int n,int* nums){
	for(int i = 1;i<=n;i++){
		cout<< nums[i];
		if(i!=n){
			cout<<" ";
		}
	}
	cout<<endl;
}



void f(int index,int min,int max,int max_index,int* nums){
	if(index>max_index){
		_print(max_index,nums);
		return;
	}
	for(int i = min;i<=max;i++){
		nums[index] = i;
		f(index+1,i+1,max,max_index,nums);
	}
}


int main(){
	int n,m;
	cin>>n>>m;
	int* nums = new int[m+1];
	f(1,1,n,m,nums);
	
	delete nums;	
	return 0;
}

