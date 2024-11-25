#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[35];
int ind[35]; 

int main(){
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		ind[i]=i;
	}
	sort(ind,ind+n,[&](int i,int j)->bool{
		return arr[i]<arr[j];
	});
	int sum = 0;
	for(int i = 0;i<n;i++){
		sum+=arr[ind[i]]*(n-i-1);
	}
	for(int i = 0;i<n;i++){
		if(i)cout<<" ";
		cout<<ind[i]+1;
	}
	printf("\n%.2lf",(double)sum/n);
	return 0;
}
