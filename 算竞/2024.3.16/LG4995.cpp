#include<iostream>
#include<algorithm>
using namespace std;
#define S(x) ((x)*(x))
int n; 
long long h[305];

int main(){
	cin>>n;
	h[0]=0;
	for(int i = 1;i<=n;i++)cin>>h[i];
	sort(h,h+n+1);
	long long ans = 0;
	int p1 = 0,p2 = n;
	while(p1<p2){
		ans+=S(h[p1]-h[p2]);
		p1++;
		if(p1>=p2)break;
		ans+=S(h[p2]-h[p1]);
		p2--;
	}
	cout<<ans<<endl;
	return 0;
}
