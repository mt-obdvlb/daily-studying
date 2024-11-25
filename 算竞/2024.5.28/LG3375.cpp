#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+6;
int nxt[N],n,m; 
string s,t;

void getNxt(){
	int j = -1;
	nxt[0]=-1;
	for(int i = 1;t[i];i++){
		while(j!=-1&&t[i]!=t[j+1])j=nxt[j];
		if(t[i]==t[j+1])j+=1;
		nxt[i]=j;
	}
}

int KMP(){
	int j = -1;
	for(int i = 0;s[i];i++){
		while(j!=-1&&s[i]!=t[j+1])j=nxt[j];
		if(s[i]==t[j+1])j+=1;
		if(t[j+1]=='\0')printf("%d\n",i-m+1+1);
	}
	return -1;
}

int main(){
	cin>>s>>t;
	n=s.size(),m=t.size();
	getNxt();
	KMP();
	for(int i = 0;i<t[i];i++){
		if(i)printf(" ");
		printf("%d",nxt[i]+1);
	}
	cout<<endl;
	return 0;
} 
