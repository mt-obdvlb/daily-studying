#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<char> v;
	string s;
	cin>>s;
	int max_len = 0;
	for(int i = 0 ;i<s.size();i++){
		int tmp_len = 0;
		int len = 0;
		int flag = 0;
		for(int j = i;j<s.size();j++){
			switch(s[j]){
				case ')':
					if(!v.empty()&&v.back()=='('){
						v.pop_back();
						tmp_len +=2;
						if(v.empty()){
							len = tmp_len;
						} 
					}else{
						flag = 1;
						break;
					}
					break;
				case ']':
					if(!v.empty()&&v.back()=='['){
						tmp_len +=2;
						v.pop_back();
						if(v.empty()){
							len = tmp_len;
						} 
					}else{
						flag = 1;
						break;
					}
					break;
				case '}':
					if(!v.empty()&&v.back()=='{'){
						v.pop_back();
						tmp_len +=2;
						if(v.empty()){
							len = tmp_len;
						} 
					}else{
						flag = 1;
						break;
					}
					break;
				case '(':
				case '{':
				case '[':
					v.push_back(s[j]);
			}
			if(flag == 1){
				flag = 0;
				break;
			}
		}
		if(len>max_len){
			max_len = len;
		}
		if(!v.empty()){
			v.clear();
		}
		tmp_len = 0;
		len = 0;
	}
	cout<<max_len<<endl;
	return 0;
}
