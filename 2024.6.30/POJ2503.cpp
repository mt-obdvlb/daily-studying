#include<sstream>
#include<string>
#include<iostream>
#include<map>

using namespace std;

map<string,string> mp;

int main(){
	string s,s1,s2;
	while(getline(cin,s)){
		if(!s.size())break;
		stringstream input(s);
		input>>s1>>s2;
		mp[s2]=s1;
	}
	while(cin>>s){
		if(mp.find(s)==mp.end())cout<<"eh"<<endl;
		else cout<<mp[s]<<endl;
	}
	return 0;
}
