#include<iostream>
#include<string>
#include<stack>


using namespace std;

int main(){
	string op;
	stack<string> forward,back;
	string cur,s;
	cur = "http://www.acm.org/";	
	while((cin>>op)){
		if(op=="QUIT")break;
		if(op=="VISIT"){
			cin>>s;
			back.push(cur);
			cur = s;
			while(!forward.empty())forward.pop();
			cout<<cur<<endl;
		}
		if(op=="BACK"){
			if(!back.empty()){
				forward.push(cur);
				cur = back.top();
				back.pop();
				cout<<cur<<endl;
			}else cout<<"Ignored"<<endl; 
		}
		if(op=="FORWARD"){
			if(!forward.empty()){
				back.push(cur);
				cur = forward.top();
				forward.pop();
				cout<<cur<<endl;
			}else cout<<"Ignored"<<endl; 
		}
		
	}
	return 0;
}
