#include<iostream>
#include<cstring>

using namespace std;

int sunday(const char *s,const char *t){
	int n =strlen(s),m = strlen(t);
	int len[256] = {0};
	for(int i = 0;i<256;i++)len[i]=m+1;
	for(int i = 0;t[i];i++)len[t[i]]=m-i;
	for(int i = 0;i+m<=n;i+=len[s[i+m]]){
		int flag = 1;
		for(int j = 0;flag&&t[j];j++){
			if(s[i+j]==t[j])continue;
			flag = 0;
		}
		if(flag)return i;
	}
}

int main(){
	cout<<sunday("adefefebc","bc");
	
	
	return 0;
}
