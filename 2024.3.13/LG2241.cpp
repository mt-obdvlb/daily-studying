#include<iostream>

using namespace std;

int n,m;


int main(){
	cin>>n>>m;
	long long sum = 0,sum_t = 0;
	for(int i =1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			sum+=min(i,j);
			sum_t+=i*j;
		}
	}
	cout<<sum<<" "<<sum_t-sum<<endl;
	return 0;
}
