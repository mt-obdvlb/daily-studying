#include<iostream>
#include<map>
using namespace std;

int n;
int arr[15];

map<int,int> m;

void dfs(int ind,int k,int p){
	if(k==n){
		for(int i = 0;i<n;i++){
			printf("%5d",arr[i]);
		} 
		cout<<endl;
		return;
	}
	for(int i = p;p;p-=i&(-i)){
		int d = m[i&(-i)];
		arr[ind]=d;
		dfs(ind+1,k+1,p-(i&(-i)));
	}
}

int main(){
	cin>>n;
	for(int i = 1,j = 1;i<25;i++,j<<=1)m[j]=i;
	dfs(0,0,(1<<(n))-1);
	return 0;
}
