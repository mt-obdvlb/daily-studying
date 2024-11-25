#include<bits/stdc++.h>

using namespace std;

const int mod =  9973;
const int base =  131;

int hash_func(const char *s){
	int h = 0,slen = strlen(s);
	for(int i = slen-1,kbase=1;i>=0;i--){
		h=(h+s[i]*kbase)%mod;
		kbase = kbase*base%mod;
	}
	return h;
}

int RabinKarp(const char *s,const char *t){
	int thash = hash_func(t);
	int nbase = 1,tlen;
	for(tlen = 0;t[tlen];tlen++)nbase=nbase*base%mod;
	for(int i = 0,h=0;s[i];i++){
		h = h*base+s[i];
		if(i>=tlen)h=((h-s[i-tlen]*nbase)%mod+mod)%mod; 
		if(i+1<tlen)continue;
		if(h!=thash)continue;
		int flag = 1;
		if(strncmp(s+i-tlen+1,t,tlen)==0)return i-tlen+1;
	}
	return -1;
}

int main(){
	char s[100],t[100];
	while(cin>>s>>t){
		cout<<RabinKarp(s,t)<<endl;
	}
	return 0;
}
