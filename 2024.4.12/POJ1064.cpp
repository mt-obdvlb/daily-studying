#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
int n,k,flag=0;
double ans,len[10005];

bool check(double x){
	int cnt = 0;
	int i = 0;
	while(i<=n){
		i++;
		cnt+=len[i]/x;
	}
	return cnt>=k;
}

int main(){
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>len[i];
	}
	sort(len+1,len+1+n);
	double l = 0.01,r = len[1],mid;
	while(r-l>eps){
		mid = (r+l)/2;
		if(check(mid)){
			flag = 1;
			ans = mid;
			l = mid;
		}else{
			r = mid;
		}
	}
	printf("%.2lf\n",flag?ans:0.00);
	return 0;
}
