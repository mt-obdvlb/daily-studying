#include<iostream>
#include<vector>
using namespace std;



int main(){
	long long ta,tb,p;
	cin>>ta>>tb>>p;
	long long b = tb;
	long long ans = 1;
	long long base(ta);
	while(b>0){
		if(b&1){
			ans = (base*ans)%p;
		}
		base =(base * base)%p;
		b>>=1;
	}
	printf("%lld^%lld mod %lld=%lld",ta,tb,p,ans);
	return 0;
}
