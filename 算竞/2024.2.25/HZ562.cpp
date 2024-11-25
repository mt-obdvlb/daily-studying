#include<iostream>

using namespace std;

int n;

int main(){
	cin>>n;
	int ans = 0;
	for(int i = 0,a;i<n;i++){
		cin>>a;
		ans^=a;
	}
	cout<<ans<<endl;
	return 0;
} 
