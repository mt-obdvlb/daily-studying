#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
	stack<int> s;
	string st;
	cin>>st;
	int flag = 1;
	for(int i =0;flag&&i<st.size();i++){
		switch(st[i]){
			case '+':
			case '-':
			case '*':
			case '/':{
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				int x;
				switch(st[i]){
					case '+':
						x=a+b;
						s.push(x);
						break;
					case '-':
						x=a-b;
						s.push(x);
						break;
					case '*':
						x=a*b;
						s.push(x);
						break;
					case '/':	
						x=a/b;
						s.push(x);
						break;	
				}
				break;
			}
			case '.':break;
			case '@':
				flag = 0;
				break;
			default:
				int x = 0;
				while(isdigit(st[i])){
					x*=10;
					x+=st[i]-'0';
					i++;
				}
				i--;
				s.push(x);
		}		
		
	}
	cout<<s.top()<<endl;
	return 0;
}
