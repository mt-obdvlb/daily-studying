#include<iostream>
#include<algorithm>

using namespace std;

int *arr = new int[5000005];

int main(){
	int n,k;
	cin>>n>>k;
	for(int i = 0;i<n;i++){
		scanf("%d",arr+i);
	}
	nth_element(arr,arr+k,arr+n);
	cout<<arr[k]<<endl;
	return 0;
}
