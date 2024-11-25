#include<iostream>
#include<string>

using namespace std;
const int N = 5e5;
int trie[N][26];
int val[N],cnt = 1;

void ins(string s){
	int p = 1;
	for(int i = 0,I = s.size();i<I;i++){
		int ind = s[i]-'a';
		if(!trie[p][ind])trie[p][ind]=++cnt;
		p = trie[p][ind];
		val[p]++;
	}
	
}

int query(string s){
	int p = 1;
	for(int i = 0,I = s.size();i<I;i++){
		int ind = s[i]-'a';
		p = trie[p][ind];
	}
	return val[p];
}

int main(){
	string s;
	while(getline(cin,s)){
		if(!s.size())break;
		ins(s);
	}
	while(cin>>s){
		cout<<query(s)<<endl;
	}
	return 0;
}
