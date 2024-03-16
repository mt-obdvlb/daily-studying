#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
long long a[1000005];

bool check(int x){
	long long s =  0;
	for(int i = 0;i<n;i++){
		s+=((a[i]>x)?a[i]-x:0);
	}
	//cout<<s<<endl;
	return s>=m;
}

int main(){
	cin>>n>>m;
	for(int i =0 ;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long l = 0,r = 2e9,mid;
	while(l<r){
		mid = (l+r+1)/2;
		if(check(mid)){
			l = mid;
		}else{
			r = mid-1;
		}
		
		//cout<<l<<" "<<mid<<" "<<r<<endl;
		//system("pause");
	}
	cout<<l<<endl;
	return 0;
}
