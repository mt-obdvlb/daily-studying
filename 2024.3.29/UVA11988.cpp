#include<bits/stdc++.h>
using namespace std;





int main(){
	string s;
	while(cin>>s){
		list<char> l;
		auto p = l.begin();
		for(auto ch : s){
			if(ch=='['){
				p=l.begin();
			}else if(ch==']'){
				p=l.end();
			}else{
				p = l.insert(p,ch);
				p++;
			}
		}
		for(auto ch:l)cout<<ch;
		puts("");
	}
	return 0;
}
