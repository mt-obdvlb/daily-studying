#include<bits/stdc++.h>

using namespace std;
int len[256],n,m;

int sunday(string &s,string &t,int pos){
	for(int i = pos;i+m<=n;i+=len[s[i+m]]){
		int flag = 1;
		if(i!=0&&i+m!=n){
			if(s[i-1]!=' '||s[i+m]!=' ')flag=0;
		}
		for(int j = 0;flag&&t[j];j++){
			if(t[j]!=s[i+j])flag=0;
		}
		if(flag)return i;
	}
	return -1;
}

int main(){
	string s,t;	
	cin>>t;
	getchar();
	getline(cin,s);
	n = s.size(),m = t.size();
	for(int i = 0;t[i];i++)t[i]=tolower(t[i]);
	for(int i = 0;s[i];i++)if(isalpha(s[i]))s[i]=tolower(s[i]); 
	for(int i = 0;i<256;i++)len[i]=m+1;
	for(int i = 0;t[i];i++)len[t[i]]=m-i;
	int flag = sunday(s,t,0),tmp,cnt=0;
	if(flag==-1)cout<<-1<<endl;
	else{
		tmp = flag;
		while(tmp!=-1){
			cnt++;
			tmp = sunday(s,t,tmp+1);
		}
		cout<<cnt<<" "<<flag<<endl;
	}
	return 0;
}
