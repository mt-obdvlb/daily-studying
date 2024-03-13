#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

int n,b;
int arr[20005];

int main(){
	cin>>n>>b;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n,greater<int>());
	int s =  0;
	for(int i = 0;i<n;i++){
		if(s>=b){
			cout<<i<<endl;
			break;
		}
		s+=arr[i];
	}
	return 0;
}
