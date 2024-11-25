#include<iostream>
#include<algorithm>
using namespace std;

int n,t;
struct c{
	int m;
	double v;
}d[105];

int main(){
	cin>>n>>t;
	for(int i = 0;i<n;i++){
		cin>>d[i].m>>d[i].v;
	}
	sort(d,d+n,[&](const c &a,const c &b)->bool{
		return a.v/a.m>b.v/b.m;
	});
	int  M = 0;
	double ans = 0.0;
	for(int i = 0;i<n;i++){
		if(t>M+d[i].m){
			ans+=d[i].v;
			M+=d[i].m;	
		}else{
			ans+=d[i].v/d[i].m*(t-M);
			break;
		}
	}
	printf("%.2lf",ans);
	return 0;
}
