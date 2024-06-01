#include<iostream>
#include<string>

using namespace std;
int nxt[1005];
int n,m;
string s,t;

void getnxt(){
	int j=-1;
	nxt[0]=-1;
	for(int i = 1;t[i];i++){
		while(j!=-1&&t[i]!=t[j+1])j=nxt[j];
		if(t[i]==t[j+1])j+=1;
		nxt[i]=j;
	}
}

int KMP(int pos){
	int j = -1;
	for(int i = pos;s[i];i++){
		while(j!=-1&&s[i]!=t[j+1])j=nxt[j];
		if(s[i]==t[j+1])j++;
		if(t[j+1]=='\0')return i-m+1;
	}
	return -1;
} 

int main(){
	while(cin>>s&&s[0]!='#'&&cin>>t){
		n=s.size(),m=t.size();
		getnxt();
		int cnt = 0;
		int pos = 0;
		while(1){
			pos = KMP(pos);
			if(pos==-1)break;
			cnt++;
			pos+=m;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
