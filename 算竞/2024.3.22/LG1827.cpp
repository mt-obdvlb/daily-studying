#include<iostream>
#include<string>

using namespace std;

string inorder;
string pre;
//CBADEFGH
//ABEDFCHG
//prev inorder
string dfs(int ll,int lr,int rl,int rr){
	if(ll==lr)return "";
	if(lr-ll==1){
		string ret="";
		ret += pre[ll];
		return ret;
	}
	char rt = pre[ll];
	int ind;
	for(ind = rl;ind<rr;ind++){
		if(inorder[ind]==rt)break;
	}
	//cout<<inorder[ind]<<endl;
	string s="";
	int cnt = ind-rl;
	s+=dfs(ll+1,ll+cnt+1,rl,ind);
	s+=dfs(ll+cnt+1,lr,ind+1,rr);	
	s+=rt;
	return s;
}

int main(){
	cin>>inorder>>pre;
	cout<<dfs(0,inorder.size(),0,pre.size())<<endl;
	return 0;
}


