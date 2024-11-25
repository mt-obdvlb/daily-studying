#include<iostream>


using namespace std;

int f[20]={0};

int main(){
	int n;
	cin>>n;
	f[0] = 1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=i;j++){
			f[i] += f[j-1]*f[i-j];
		}		 
	}
	cout<<f[n]<<endl;
	return 0;
}
