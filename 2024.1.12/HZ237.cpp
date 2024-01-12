	#include<bits/stdc++.h>
	
	using namespace std;
	
	int nums[10];
	
	int _count = 0;
	
	void _print(int n){
		for(int i = 1;i<=n;i++){
			cout<<nums[i];
			if(i!=n){
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
	bool is_had(int n){
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				if(nums[i]==nums[j]){
					return true;
				}
			}
		}
		return false;
	}
	
	void f(int index,int max){
		if(index>max){
			if(!is_had(max)){
				_print(max);	
			}
			return;
		}
		for(int i = 1;i <= max;i++){
			for(int j = index;j<=max;j++){
				nums[j] = i;
				f(j+1,max);
			}
		}
	}
	
	int main(){
		int n;
		cin>>n;
		f(1,n);
		return 0;
	}
