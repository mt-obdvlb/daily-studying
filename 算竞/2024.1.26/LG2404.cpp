#include<iostream>

using namespace std;

int ans[20];

void print(int n){
	if(n<2){
		return;
	}
	for(int i = 0;i<n;i++){
		if(i)cout<<"+";
		cout<< ans[i];
	}
	cout<<endl;
}


void dfs(int ind,int k,int sum ,int target){
	if(sum == target){
		print(ind);
		return;
	}
	if(sum+k>target)return;
	for(int i = k;i<=target;i++){
		ans[ind] = i;
		dfs(ind+1,i,sum+i,target); 
	} 
}


int main(){
	int n;
	cin >> n;
	dfs(0,1,0,n);
	return 0;
}
