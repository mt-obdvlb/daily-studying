#include<iostream>
#include<cstring>

using namespace std;

int sunday(const char *s,const char *t){
	int len[256]={0};
	int n = strlen(s),m=strlen(t);
	for(int i =0;i<256;i++)len[i]=m+1;
	for(int i =0;t[i];i++)len[t[i]]=m-i;
	for(int i = 0;i+m<=n;i+=len[s[i]]){
		int flag = 1;
		for(int j = 0;flag&&t[j];j++){
			if(s[i+j]==t[j])continue;
			else flag = 0;
		}
		if(flag)return i;
	}
	return -1;
}

int main(){
	cout<<sunday("abcdef","de")<<endl;
	
	
	return 0;
}
