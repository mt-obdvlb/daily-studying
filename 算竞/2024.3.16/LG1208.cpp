#include<iostream>
#include<algorithm>
using namespace std;

int n,m;

struct Data{
	int p,a;
}d[2000005];

int main(){
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		scanf("%d%d",&d[i].p,&d[i].a);
	}
	sort(d,d+n,[&](const Data &ta,const Data &tb)->bool{
		return ta.p<tb.p;
	});
	int s = 0;
	int ans = 0;
	for(int i = 0;i<n;i++){
		if(d[i].a+s>=n){
			ans+=d[i].p*(n-s);
			break;
		}else{
			s+=d[i].a;
			ans += d[i].a*d[i].p;
		}
	}
	cout<<ans<<endl; 
	return 0;
}
