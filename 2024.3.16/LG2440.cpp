#include<iostream>
#include<algorithm>
using namespace std;

long long n,k;
long long l[100005];

bool check(long long x){
	long long s=0;
	for(long long i = 0;i<n;i++){
		s+=l[i]/x;
	}
	return s>=k;
}

int main(){
	cin>>n>>k;
	for(long long i =0;i<n;i++)cin>>l[i];
	sort(l,l+n);
	long long l = 0,r = 1e9,m;
	while(l<r){
		m = (l+r+1)/2;
		if(check(m)){
			l = m;
		}else{
			r = m-1;
		}
	}
	cout<<l<<endl;
	return 0;
}
