#include<iostream>
#include<cstring>

using namespace std;

int* getNext(const char *t){
	int tlen = strlen(t),j = -1;
	int *next = (int*)malloc(sizeof(int)*tlen);
	next[0]=-1;
	for(int i = 0;t[i];i++){
		while(j!=-1&&t[j+1]!=t[i])j=next[j];
		if(t[j+1]==t[i])j+=1;
		next[i]=j;
	}
	return next;
}

int KMP(const char *s,const char *t){
	int* next = getNext(t);
	int j = -1,tlen = strlen(t);
	for(int i = 0;s[i];i++){
		while(j!=-1&&s[i]!=t[j+1])j=next[j];
		if(s[i]==t[j+1])j+=1;
		if(t[j+1]=='\0')return i-tlen+1;		
	}
	return -1;
}

int main(){
	cout<<KMP("cefadfasdf","cef")<<endl;;
	
	return 0;
}
