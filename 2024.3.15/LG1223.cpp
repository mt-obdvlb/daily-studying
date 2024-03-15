#include<iostream>
#include<algorithm>

using namespace std;

int n;
long long a[1005];
long long b[1005];
long long ans =0;
int ind[1005];

int main(){
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		
		ind[i]=i;
	}
	sort(ind,ind+n,[&](int i,int j)->bool{
		return a[i]<a[j];
	});
	for(int i = 0;i<n;i++){
		if(i)cout<<" ";
		cout<<ind[i]+1;
	}
	cout<<endl;
	sort(a,a+n);
	b[0]=a[0];
	for(int i = 1;i<n;i++){
		b[i]=b[i-1]+a[i];
	}
	double ans = 0.0;
	for(int i = 0;i<n-1;i++){
		ans+=((double)b[i])/n;
	}
	printf("%.2lf\n",ans);
	
	return 0;
}
