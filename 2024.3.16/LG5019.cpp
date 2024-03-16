#include<iostream>

using namespace std;

int n;
int arr[100005];
int ind[100005];
int cnt = 0;

int main(){
	cin>>n;
	int m=10005;
	for(int i =0 ;i<n;i++){
		scanf("%d",arr+i);
	}
	for(int i = 1;i<n;i++){
		if(arr[i]>arr[i-1])cnt+=arr[i]-arr[i-1];
	}	
	cout<<cnt+arr[0]<<endl;
	return 0;
}
