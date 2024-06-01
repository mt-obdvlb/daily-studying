#include<bits/stdc++.h>

using namespace std;

int shift_and(const char *s,const char *t){
	int code[256],n=0;
	for(;t[n];n++)code[t[n]]|=(1<<n);
	int p = 0;
	for(int i = 0;s[i];i++){
		p = (p<<1|1)&code[s[i]];
		if(p&(1<<(n-1)))return i-n+1;
	}
	return -1;
}

int main(){
	char s[100],t[100];
	while(cin>>s>>t){
		cout<<shift_and(s,t)<<endl;
	}
	return 0;
}
