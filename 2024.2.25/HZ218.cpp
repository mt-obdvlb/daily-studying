#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[100005],ind[100005];

int main(){
	cin>>n;
	for(int i = 0;i<n;i++){
		scanf("%d",arr+i);
		ind[i]=i;
	}
	sort(ind,ind+n,[&](int i,int j)->bool{
		if(arr[i]!=arr[j])return arr[i]<arr[j];
		return i<j;
	});
	for(int i = 0;i<n;i++){
		if(i)cout<<" ";
		cout<<ind[i]+1;
	}
	return 0;
}
