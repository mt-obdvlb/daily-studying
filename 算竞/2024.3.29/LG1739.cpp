#include<bits/stdc++.h>

using namespace std;

string s;
int flag = 1,cnt = 0;

int main(){
	cin>>s;
	stack<char> st;
	for(int i = 0;flag&&i<s.size();i++){
		
		switch(s[i]){
			case '@':
				flag = 0;
				break;
			case '(':
				cnt++;
				break;				
			case ')':
				cnt--;
				break;	
		}	
		if(cnt<0){
			flag = 0;
			cout<<"NO"<<endl;
			return 0;
			break;
		}
	}
	if(cnt==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
