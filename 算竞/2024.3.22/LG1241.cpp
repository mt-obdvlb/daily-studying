#include<iostream>
#include<stack>
using namespace std;

string s;

int vis[1000000];


int main(){
	cin>>s;
	stack<char> st;
	for(int i = 0;i<s.size();i++){
		switch(s[i]){
			case '(':
				st.push(i);
				break;
			case '[':
				st.push(i);
				break;
			case ')':
				if(st.empty()||s[st.top()]!='('){
					s.insert(s.begin()+ i,'(');
					vis[i]=1;
					i++;
				}else{
					vis[st.top()]=1;
					st.pop();
				}
				break;
			case ']':
				if(st.empty()||s[st.top()]!='['){
					s.insert(s.begin()+ i,'[');
					vis[i]=1;
					i++;
				}else{
					vis[st.top()]=1;
					st.pop();
				}
				break;
	
		}
	}
	for(int i = 0,j = 0;i<s.size();i++,j++){
		if(vis[j])continue;
		switch(s[i]){
			case '(':
				j--;
				s.insert(s.begin()+i+1,')');
				break;
			case '[':
				j--;
				s.insert(s.begin()+i+1,']');
				break;
		}
	}
	cout<<s<<endl;
	return 0;
}
