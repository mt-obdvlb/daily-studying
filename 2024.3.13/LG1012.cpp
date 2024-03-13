#include<iostream>
#include<algorithm>
using namespace std;

int n;
string s[25];
string ans="";

int main(){
	cin>>n;
	for(int i = 0;i<n;i++)cin>>s[i];
	sort(s,s+n,[&](const string &a,const string &b)->bool{
		return (a+b)>(b+a);
	});
	for(int i = 0;i<n;i++)ans+=s[i];
	cout<<ans<<endl;
	return 0;
}
