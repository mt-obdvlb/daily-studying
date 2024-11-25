#include<bits/stdc++.h>
using namespace std;

int *getNext(const char *t){
	int tlen = strlen(t);
	int *nxt = new int[tlen];
	nxt[0] = -1;
	int j = -1;
	for(int i = 1;t[i];i++){
		while(j!=-1&&t[i]!=t[j+1]){
			j = nxt[j];
		}
		if(t[i]==t[j+1])j+=1;
		nxt[i] = j;
	}
	return nxt;
}

int KMP(const char *s,const char *t){
	int *nxt = getNext(t);
	int j = -1,tlen=strlen(t);
	for(int i = 0;s[i];i++){
		while(j!=-1&&s[i]!=t[j+1])j=nxt[j];
		if(s[i]==t[j+1])j+=1;
		if(t[j+1]=='\0')return i-tlen+1;
	}
	return -1;
}

int main(){
	char s[100],t[100];
	while(cin>>s>>t){
		cout<<KMP(s,t)<<endl;
	}
	return 0;
}
