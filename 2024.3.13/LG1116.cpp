#include<iostream>

using namespace std;

int n;
int arr[10005];

int main(){
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = n-1;j>i;j--){
			if(arr[j]<arr[j-1]){
				swap(arr[j],arr[j-1]);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
