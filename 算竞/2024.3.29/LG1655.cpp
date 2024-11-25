#include<bits/stdc++.h>

using namespace std;

int main(){
	int cnt = 0;
	char ch;
	while(~scanf("%c",&ch)){
		if(ch=='\n')break;
		if(ch=='(')cnt++;
		if(ch==')')cnt--;
		if(cnt<0){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	if(cnt==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
