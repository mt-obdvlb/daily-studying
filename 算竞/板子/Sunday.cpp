#include<bits/stdc++.h>

using namespace std;

int Sunday(const char *s,const char *t){
	int len[256];
	int n = strlen(s),m = strlen(t);
	for(int i = 0;i<256;i++)len[i]=m+1;
	for(int i = 0;t[i];i++)len[t[i]]=m-i;
	for(int i = 0;i+m<=n;i+=len[s[i+m]]){
		int flag = 1;
		for(int j = 0;t[j];j++){
			if(s[i+j]==s[j])continue;
			flag=0;
		}
		if(flag)return i;
	}
	return -1;
}

int main(){
	
	
	return 0;
}
