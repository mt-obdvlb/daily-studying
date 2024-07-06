#include<iostream>
#include<string>
#include<cstring>

using namespace std;
const int N = 2e5;
int Trie[N][10];
int ed[N],cnt,flag;

void ins(string s){
	int len = s.size(),p = 1;
	for(int i = 0;i<len;i++){
		int ind = s[i]-'0';
		if(!Trie[p][ind])Trie[p][ind]=++cnt;
		else if(i==len-1)flag=1;
		p = Trie[p][ind];
		if(ed[p])flag=1;
	}
	ed[p]=1;
}

void init(){
	memset(Trie,0,sizeof(Trie));
	memset(ed,0,sizeof(ed));
	cnt = 1;
	flag = 0;
}

int main(){
	int T;
	string s;
	cin>>T;
	while(T--){
		init();
		int n;	
		cin>>n;
		while(n--){
			cin>>s;
			if(flag)continue;
			ins(s);	
		}
		if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
