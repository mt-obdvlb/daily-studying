#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[1000005];

int main(){
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i = 0;i<n;i++){
		if(i)cout<<" ";
		cout<<arr[i];
	}
	return 0;
} 
