#include<bits/stdc++.h>

using namespace std;

int n,t;
int l[256],r[256];

string dfs(int o){
	string ret ="";
	if(o=='*')return ret;
	ret+=(char(o));
	if(l[o]=='*'&&r[o]=='*'){
		return ret;
	}
	ret+=dfs(l[o]);
	ret+=dfs(r[o]);
	return ret;
}

int main(){
	cin>>n;
	int rt;
	for(int i = 0;i<n;i++){
		char a,b,c;
		cin>>a>>b>>c; 
		if(i==0)rt = (int)a;
		l[a]=b,r[a]=c;
	}
	cout<<dfs(rt)<<endl;
	return 0;
}
