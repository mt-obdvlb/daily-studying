#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

struct Data{
	double l,r;	
}arr[1005];

int main(){
	int n;
	double r,x,y;
	cin>>n>>r;
	for(int i = 0;i<n;i++){
		cin>>x>>y;
		if(y>r){
			cout<<-1<<endl;
			return 0;
		}
		double tmp = sqrt(r*r - y*y);
		arr[i].l = x-tmp;
		arr[i].r = x+tmp;
	}
	sort(arr,arr+n,[&](const Data &a,const Data &b)->bool{
		return a.r<b.r;
	});
	int ans = 1;
	double pos = arr[0].r;
	for(int i = 1;i<n;i++){
		if(arr[i].l>pos){
			ans++;
			pos = arr[i].r;
		}
	}
	cout<<ans<<endl;
	return 0;
}
