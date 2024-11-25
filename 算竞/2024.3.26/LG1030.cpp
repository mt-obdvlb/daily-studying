#include<bits/stdc++.h>

using namespace std;

string in,post;	
int n;

string dfs(int il,int ir,int pl,int pr){
	string s="";
	if(il==ir)return "";
	s+=post[pr-1];
	if(il==ir-1)return s;
	int ind = -1;
	for(int i = il;i<ir;i++){
		if(in[i]==post[pr-1]){
			ind = i;
			break;
		}
	}
	int cnt = ind-il;
	s+=dfs(il,il+cnt,pl,pl+cnt);
	s+=dfs(il+cnt+1,ir,pl+cnt,pr-1);
	return s;
}

int main(){
	cin>>in>>post;
	n = in.size();
	cout<<dfs(0,n,0,n)<<endl;
	return 0;
}
