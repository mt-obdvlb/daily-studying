#include<iostream>
#include<cmath>
using namespace std;

long long x,ans = 0;
string s;

int main(){
	cin>>x>>s;
	int n=s.size();
	for(int i = 0,j = n-1;i<n;i++,j--){
		ans += (s[j]-'0')*pow(x,i);
	}
	cout<<ans<<endl; 
	return 0;
}
