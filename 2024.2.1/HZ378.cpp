#include<bits/stdc++.h>


using namespace std;

int main(){
	stack<char> s;
	string a;
	cin>>a;
	int flag = 1;
	for(int i=0,I=a.size();i<I&&flag;i++){
		switch(a[i]){
			case ')':
				if(!s.empty()&&s.top()=='(')s.pop();
				else flag = 0;
				break; 
			case ']':
				if(!s.empty()&&s.top()=='[')s.pop();
				else flag = 0;
				break;
			case '}':
				if(!s.empty()&&s.top()=='{')s.pop();
				else flag = 0;
				break;
			case '(':
			case '[':
			case '{':
				s.push(a[i]);
		}
	}
	if(!s.empty())flag=0;
	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
