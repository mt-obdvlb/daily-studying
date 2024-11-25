#include<bits/stdc++.h>

using namespace std;

int * getnxt(const char *t){
	int n = strlen(t);
	int *nxt = (int*)malloc(sizeof(int)*n);
	nxt[0] = 0;
	int j = -1;
	for(int i = 0;t[i];i++){
		while(j!=0&&t[i]!=t[j+1])j = nxt[j];
		if(t[i]==t[j+1])j++;
		nxt[i]=j;
	}
	return nxt;
}

int KMP(const char *s,const char *t){
	int *nxt = getnxt(t);	
	int j = -1;
	int tlen = strlen(t);
	for(int i = 0;s[i];i++){
		while(j!=-1&&s[i]!=t[j+1])j=nxt[j];
		if(s[i]==t[j+1])j++;
		if(t[j+1]=='\0')return i-tlen+1;
	}
	return -1;
}

int main(){
	char t[50] = "abcaabbcabcaabdab";
	int *nxt = getnxt(t);
	for(int i = 0; i < 50; i++){
		cout<<nxt[i]<<",";
	}
	return 0;
}
