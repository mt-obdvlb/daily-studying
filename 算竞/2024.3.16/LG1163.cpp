#include<iostream>
#include<cmath>
using namespace std;

double w0,w,m;


int main(){
	cin>>w0>>w>>m;
	double l=0.0,r=300.0,mid;
	while(r-l>0.0001){
		mid=(l+r)/2;
		if(w>(w0*mid)/(1.0-pow(1.0/(1.0+mid),m))){
			l = mid;
		}else{
			r = mid;
		}
	}
	printf("%.1lf",l*100.0);
	return 0;
}
