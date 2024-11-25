#include<bits/stdc++.h>

using namespace std;

int n,a[100],rr,ll;

bool check(int x){
	int p1 = 0,p2 = n-1;
	int t = 0,cnt = 0;
	while(p1<p2){
		if(t+a[p2]<=x){
			cnt++;
			t+=a[p2];
			p2--;
		}else if(t+a[p1]<=x){
			cnt++;
			t+=a[p1];
			p1++;
		}else{
			return false;
		}
		if(t==x){
			t = 0;
			if(cnt==1)return false;
			cnt = 0;
		}
	}
	return (t==0&&cnt==0);
}


int main(){
	while(cin>>n&&n){	
		rr = 0,ll=0;	
		for(int i = 0;i<n;i++){
			cin>>a[i];
			rr +=a[i];
			ll=max(a[i],ll);
		}
		sort(a,a+n);
		int l = ll,r = 1+rr/2,mid;
		int i;
		for(i = ll;i<=r;i++){
			if(check(i))break;
		}
		cout<<i<<endl;
	}
	return 0;
}
