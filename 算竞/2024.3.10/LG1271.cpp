#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int arr[2000005];

int main(){
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		cin>>arr[i];
	}
	sort(arr,arr+m);
	for(int i = 0;i<m;i++){
		if(i)cout<<" ";
		cout<<arr[i];
	}
	return 0;
}
