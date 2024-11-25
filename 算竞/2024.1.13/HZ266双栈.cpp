#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	vector<char> c_v;
	vector<int> i_v;
	int total = 0;
	for(int i = 0;i<s.size();i++){
		switch(s[i]){
			case '^':
				c_v.push_back(s[i]);
				break;
			case '/':
			case '*':
				if(c_v.empty()||c_v.back()=='+'||c_v.back()=='-'||c_v.back()=='/'||c_v.back()=='*'||c_v.back()=='('){
					c_v.push_back(s[i]);
				}else{
					char tmp = c_v.back();
					c_v.pop_back();
					int val2 = i_v.back();
					i_v.pop_back();
					int val1 = i_v.back();
					i_v.pop_back();
					switch(tmp){
						case '^':
							int val = (int)pow(val1,val2);
							i_v.push_back(val);
							break;
					}
					c_v.push_back(s[i]);
				}
				break;
			case '(':
				c_v.push_back(s[i]);
				break;
			case ')':{
				if(c_v.empty()||i_v.size()==1){
					break;
				}
				do {
					char tmp = c_v.back();
					c_v.pop_back();
					if(tmp == '('){
						break;
					}
					int val2 = i_v.back();
					i_v.pop_back();
					int val1 = i_v.back();
					i_v.pop_back();
					switch (tmp) {
						case '+': {
							int val = val1 + val2;
							i_v.push_back(val);
							break;
						}
				
						case '-': {
							int val = val1 - val2;
							i_v.push_back(val);
							break;
						}
						case '*': {
							int val = val1 * val2;
							i_v.push_back(val);
							break;
						}
						case '/': {
							int val = val1 / val2;
							i_v.push_back(val);
							break;
						}
						case '^': {
							int val = (int)pow(val1, val2);
							i_v.push_back(val);
							break;
						}
					}
					
				} while (1);
				break;
			}
			case '+':
			case '-':{
				if(i == 0||(!isdigit(s[i-1])&&s[i-1]!=')')){
					int tmp = i;
					int sum = 0;
					i++;
					while(isdigit(s[i])){
						sum*=10;
						sum += s[i] - '0';
						i++;
					}
					if(s[tmp] == '-'){
						sum = -sum;
					}
					i--;
					i_v.push_back(sum);
				}else if(c_v.empty()||c_v.back()=='('){
					c_v.push_back(s[i]);
				}else{
					while(1){
						if(c_v.empty()){
							break;
						}
						char tmp = c_v.back();
						if(tmp!='*'&&tmp!='/'&&tmp!='^'&&tmp!='+'&&tmp!='-'){
							break;
						}
						c_v.pop_back();
						int val2 = i_v.back();
						i_v.pop_back();
						int val1 = i_v.back();
						i_v.pop_back();
						switch(tmp){
							case '+': {
								int val = val1 + val2;
								i_v.push_back(val);
								break;
							}
				
							case '-': {
								int val = val1 - val2;
								i_v.push_back(val);
								break;
							}
							case '*':{
								int val = val1 * val2;
								i_v.push_back(val);
								break; 
							}
							case '/':{
								int val = val1 / val2;
								i_v.push_back(val);
								break;
							}
							case '^':
								int val = (int)pow(val1,val2);
								i_v.push_back(val);
								break;
						}
					}
					c_v.push_back(s[i]);
				}
				break;
			} 
			default:
				if(isspace(s[i])){
					break;
				}
				int sum = 0;
				while(isdigit(s[i])){
					sum*=10;
					sum += s[i] - '0';
					i++;
				}
				i--;
				i_v.push_back(sum);
		}
	}
	if(c_v.empty()||i_v.size()==1){
		cout<<i_v.back()<<endl;
		return 0;
	}
	do {
		char tmp = c_v.back();
		c_v.pop_back();
		int val2 = i_v.back();
		i_v.pop_back();
		int val1 = i_v.back();
		i_v.pop_back();
		switch (tmp) {
			case '+': {
				int val = val1 + val2;
				i_v.push_back(val);
				break;
			}
	
			case '-': {
				int val = val1 - val2;
				i_v.push_back(val);
				break;
			}
			case '*': {
				int val = val1 * val2;
				i_v.push_back(val);
				break;
			}
			case '/': {
				int val = val1 / val2;
				i_v.push_back(val);
				break;
			}
			case '^': {
				int val = (int)pow(val1, val2);
				i_v.push_back(val);
				break;
			}
		}
		if(c_v.empty()||i_v.size() == 1){
			cout<<i_v.back()<<endl;
			return 0;
		}
	} while (1);
	return 0;
}
