#include<iostream>

using namespace std;

int n,m;
int arr[100005];

int main(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++)scanf("%d",arr+i);
	for(int i = 0;i<m;i++){
		int x;
		scanf("%d",&x);
		int l = 1,r=n,mid;
		while(l<r){
			mid=(l+r+1)/2;
			if(arr[mid]<=x){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		mid=(l+r+1)/2;
		if(i)cout<<" ";
		printf("%d",arr[mid]);
	}
	return 0;
}
