#include<bits/stdc++.h>

using namespace std;

int l[30],r[30];
char rt[30],cl[30],rl[30];


int n;

string dfs(int i){
	string ret ="";
	ret+=rt[i];
	if(l[i])ret+=dfs(l[i]);
	if(r[i])ret+=dfs(r[i]);
	return ret;
}

int main(){
	cin>>n;
	string ans;
	for(int i = 1;i<=n;i++){
		cin>>rt[i]>>cl[i]>>rl[i];
	}
	for(int i = 1;i<=n;i++){
		if(cl[i]!='*'){
			for(int j =1 ;j<=n;j++){
				if(rt[j]==cl[i]){
					l[i]=j;
					break;
				}
			}
		}
		if(rl[i]!='*'){
			for(int j =1 ;j<=n;j++){
				if(rt[j]==rl[i]){
					r[i]=j;
					break;
				}
			}	
		}
	}
	cout<<dfs(1)<<endl;
	return 0;
}
