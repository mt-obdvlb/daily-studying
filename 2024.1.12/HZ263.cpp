#include<bits/stdc++.h>

using namespace std;

int Count = 0;
int nums[25];

int used[25] = {0};

void _print(int n){
	for(int i = 1;i<=n;i++){
		cout<<nums[i];
	}
	cout<<endl;
}

bool is_valid(int n){
	stack<int> s;
	int x = 1;
	for(int i = 1;i<=n;i++){
		if(s.empty()||s.top()<nums[i]){
			while(x<=nums[i]){
				s.push(x);
				x++;
			}
		}
		if(s.empty()||s.top()!=nums[i]){
			return false;
		}
		s.pop();
	}
	return true;
}
/*
void f(int index,int n){
	if(Count >=20){
		return;
	}
	if(index > n){
		if(is_valid(n)){
			Count++;
			_print(n);
		}
		return;
	}
	for(int i = 1;i<=n;i++){
		if(used[i] == 0){
			used[i] = 1;
			nums[index] = i;
			f(index+1,n);
			if(Count>=20){
				return;
			}
			used[i] = 0;
		} 
	}
}
*/
int main(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		nums[i] = i;
	}
	do{
		if(is_valid(n)){
			Count++;
			_print(n);
		}
	}while(next_permutation(nums+1,nums+n+1)&&Count<20);
	return 0;
}
