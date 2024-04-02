#include<bits/stdc++.h>

using namespace std;

string pre,in;

string dfs(int ll,int lr,int rl,int rr){
	string ret ="";
	if(ll==lr)return "";
	if(ll==lr-1){
		ret+=pre[ll];
		return ret;	
	}
	char rt = pre[ll];
	int ind = 0,cnt = 0;
	for(ind = rl;ind<rr;ind++,cnt++){
		if(in[ind]==rt)break;
	}
	ret+=dfs(ll+1,ll+1+cnt,rl,ind);
	ret+=dfs(ll+1+cnt,lr,ind+1,rr);
	ret += pre[ll];
	return ret;
}

int main(){
	while(cin>>pre>>in){
		cout<<dfs(0,pre.size(),0,in.size())<<endl;
	}	
	return 0;
}
