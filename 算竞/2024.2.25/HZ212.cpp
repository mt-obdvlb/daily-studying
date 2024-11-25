#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	string s[15];
	for(int i = 0;i<10;i++)cin>>s[i];
	sort(s,s+10);
	for(int i = 0;i<10;i++)cout<<s[i]<<endl;
	return 0;
}
