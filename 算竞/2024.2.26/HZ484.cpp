#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){
	string s;
	int len[256]={0};
	int maxLen=0;
	while(cin>>s){
		for(int i = 0;i<s.size();i++){
			len[s[i]]++;
		}
	}
	int ans[26];
	for(int i = 'A',j=0;i<='Z';i++,j++){
		ans[j]=i;
		maxLen=max(maxLen,len[ans[j]]);	
	}
	for(int i = maxLen;i>0;i--){
		int r = 0;
		for(int j = 0;j<26;j++){
			if(len[ans[j]]>=i)r=j;
			else r=min(r,j);
		}
		for(int j = 0;j<=r;j++){
			if(j)cout<<" ";
			if(len[ans[j]]>=i)printf("*");
			else cout<<" ";
		}
		cout<<endl; 
	}
	for(int i = 0;i<26;i++){
		if(i)cout<<" ";
		printf("%c",'A'+i);
	}
	return 0;
}
