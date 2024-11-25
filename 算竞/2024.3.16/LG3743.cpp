#include<iostream>

using namespace std;

int n;
double p;
double a[100005],b[100005];

bool check(double t){
	double s = t*p;
	for(int i = 0;i<n;i++){
		if(s<0.0)return false;
		if(a[i]*t<=b[i])continue;
		s-=a[i]*t-b[i];
	}
	return s>=0.0;
}

int main(){
	cin>>n>>p;
	double sum = 0.0;
	for(int i = 0;i<n;i++){
		scanf("%lf%lf",a+i,b+i);
		sum+=a[i];
	}
	if(sum<=p){
		cout<<-1<<endl;
		return 0;
	}
	double l=0.0,r =1e11,m;
	while(r-l>0.000001){
		m=(r+l)/2;
		if(check(m)){
			l = m;
		}else{
			r = m;
		}
	}
	printf("%.10lf",l);
	return 0;
}
