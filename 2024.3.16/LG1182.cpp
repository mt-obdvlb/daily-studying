#include<iostream>

using namespace std;

int n,m;
long long a[100005];

bool check(int x){
	int tot = 0;
	int i = 0;
	int now =a[i];
	while(i<n){
		i++;
		if(now+a[i]>x){
			now=0;
			tot++;
			i--;
		}else{
			now+=a[i];
		}
		if(tot>m)return false;
	}
	if(now>0)tot++;
	return tot<=m;
}

int main(){
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>a[i];
	long long l = 0,r = 1e9,m;
	while(l<r){
		m = (l+r)/2;
		if(check(m)){
			r=m;
		}else{
			l=m+1;
		}
	}
	cout<<l<<endl;
	return 0;
}
