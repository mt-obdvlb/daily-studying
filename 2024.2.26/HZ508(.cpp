#include<iostream>
#include<algorithm>
using namespace std;

int arr[1005];

int main(){
	int n=0,ans=0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	int a = arr[1],b=arr[2];
	for(int i =n;i>=2;i-=2){
		int c = arr[i-1],d=arr[i];
		if(i>3){
			ans+=min(a+2*b+d,2*a+c+d);
		}else if(i==3){
			ans+=b+a+d;
		}else{
			ans+=b;
		}
	}
	cout<<ans<<endl;
	return 0;
}
