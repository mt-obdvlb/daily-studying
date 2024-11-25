#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;


int main(){
	string s;
	int k;
	cin >> s>> k;
	for(int i = 0;i<k;i++){
		int pos = 0;
		while(pos+1<s.size()&&s[pos]<=s[pos+1])pos++;
		s.erase(pos,1);
	} 
	while(s[0] == '0'){
		s.erase(0,1);
	}
	cout<< s<<endl;
	return 0;
}
