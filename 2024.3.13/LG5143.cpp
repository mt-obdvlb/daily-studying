#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define S(x) ((x) * (x))

int n;
int x[50005],y[50005],z[50005];
int ind[50005]; 

int main(){
	cin>>n;
	x[0]=y[0]=z[0]=0;
	for(int i = 1;i<=n;i++){
		cin>>x[i]>>y[i]>>z[i];
		ind[i]=i;
	}
	sort(ind+1,ind+1+n,[&](int i,int j)->bool{
		return z[i]<z[j];
	});
	double ans = 0.0;
	for(int i = 2;i<=n;i++){
		ans=ans+sqrt(S(x[ind[i]]-x[ind[i-1]])+
		S(y[ind[i]]-y[ind[i-1]])+
		S(z[ind[i]]-z[ind[i-1]]));
	}
	printf("%.3lf",ans);
	return 0;
}
