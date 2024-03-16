#include<iostream>

using namespace std;

int length,n,k;
int a[100005];

bool check(int x){
	int now = a[0];
	int i = 0;
	int tot = 0;
	while(i<n){
		i++;
		if(a[i]-now>x){
			now +=x;
			tot++;
			i--;
		}else{
			now = a[i];
		}
		if(tot>k)return false;
	}
	return tot<=k;
}

int main(){
	cin>>length>>n>>k;
	for(int i = 0;i<n;i++)cin>>a[i];
	int l = 0,r = length,mid;
	while(l<r){
		mid = (l+r)/2;
		if(check(mid)){
			r = mid;
		}else{
			l = mid+1;
		}
	}
	cout<<l<<endl;
	return 0;
}
