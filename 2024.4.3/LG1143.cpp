#include<bits/stdc++.h>

using namespace std;

int mp1[256];
char mp2[16];

int main(){
	int n,m;
	string s;
	cin>>n>>s>>m;
	for(int i = '0';i<='9';i++)mp1[i]=i-'0',mp2[i-'0']=i;
	for(int i = 'A';i<='F';i++)mp1[i]=i-'A'+10,mp2[i-'A'+10]=i;
	int s10=0;
	string ans;
	for(int i = 0;i<s.size();i++){
		s10 += mp1[s[s.size()-i-1]]*pow(n,i);
	}
	while(s10){
		ans+=mp2[s10%m];
		s10/=m;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
	return 0;
}
