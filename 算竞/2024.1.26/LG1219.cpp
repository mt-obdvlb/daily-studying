#include<iostream>
#include<unordered_map>

#define MASK(n) ((1<<(n+1))-2)
#define MAX_N 14

using namespace std;

unordered_map<int,int> h;
int total = 3;
int arr[MAX_N];

void print(int n){
	for(int i = 0;i<n;i++){
		if(i){
			cout<<" ";
		}
		cout<< arr[i+1];
	}
	cout<<endl;
	total--;
}

int dfs(int i,int t1,int t2,int t3,int n){
	if(i>n){
		if(total){
			print(n);
		}
		return 1;
	}	
	int ans = 0;
	for(int t = t1;t;t -=(-t & t)){
		int j = h[t & -t];
		if(((1<<(i + j - 1)) & t2 )&&((1 << (n - j + i))& t3)){
			arr[i] = j;
			ans += dfs(i+1,t1 ^ (1<<j),t2 ^ (1<<(i+j-1)),t3 ^(1 << (n-j+i)),n);
		}
	}
	return ans;
}


int main(){
	int n;
	cin>>n;
	for(int i = 0;i<2*n;i++){
		h[1 << i] = i;
	}
	cout<<dfs(1,MASK(n),MASK(2*n-1),MASK(2*n-1),n)<<endl;
	return 0;
}
