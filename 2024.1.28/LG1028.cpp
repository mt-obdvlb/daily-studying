#include<iostream>


using namespace std;

int main(){
	int n;
	cin>>n;
	int f[1005];
	f[1] = 1;
	for(int i = 2;i<=n;i++){
		f[i] = 1;
		for(int j = i/2;j>=1;j--){
			f[i] += f[j];
		}
	}	
	cout<<f[n]<<endl;
	return 0;
}
