#include<iostream>
#include<cmath>

#define MAX_N 25

using namespace std;

int arr[MAX_N];
long long cnt = 0;

bool is_prime(int x){
	for(int i =2;i*i<=x;i++){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

void dfs(int a,int ind,int n,int k,int sum){
	if (a == k) {
		
        if (is_prime(sum)) cnt += 1;
        return ;
    }
	for (int i = ind; i <= n; i++) {
        dfs(a+1,i + 1, n, k, sum + arr[i]);
    }
}

int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> arr[i];
	}
	dfs(0,1,n,k,0);
	cout<< cnt <<endl; 
	return 0;
}
