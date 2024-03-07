#include<iostream>
#include<string>
using namespace std;
string s;

bool is_Y(char x){
	switch(x){
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			return true;
			break;
		default:
			return false;
	}
	return false;
}

int main(){
	cin>>s;
	int flag=1;
	int pre=s.size(),ans = 0;
	for(int i = 0;i<s.size();i++){
		if(!is_Y(s[i]))continue;
		ans=max(ans,i-pre);
		pre=i;
	}
	cout<<ans<<endl; 
	return 0;
}
