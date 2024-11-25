#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
int n;
double h[1005],ans;

bool check(double x){
	h[2] = x;
	for(int i = 3;i<=n;i++){
		h[i] = h[i-1]*2 +2.0-h[i-2];
		if(h[i]<eps)return false;
	}
	ans = h[n];
	return true;
}

int main(){
	cin>>n>>h[1];
	double l = 0.0,r = 0x3f3f3f3f,mid;
	while(r-l>eps){
		mid = (l+r)/2;
		if(check(mid)){
			r = mid;
		}else{
			l = mid;
		}
	}
	printf("%.2lf",ans);
	return 0;
}
