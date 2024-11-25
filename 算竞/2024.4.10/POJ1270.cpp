#include<bits/stdc++.h>

using namespace std;

string s1,s2,u,v;

int g[30][30],s[30],cnt,ans[30],indeg[30];

void dfs(int x){
	if(x>cnt){
		for(int i = 1;i<=cnt;i++)cout<<(char)(ans[i]+'a');
		cout<<endl;
	}
	for(int i = 0;i<26;i++){
		if(!s[i])continue;
		if(indeg[i])continue;
		s[i]--;
		for(int j = 0;j<26;j++){
			if(g[i][j])indeg[j]--;
		}
		ans[x] = i;
		dfs(x+1);
		s[i]++;
		for(int j = 0;j<26;j++){
			if(g[i][j])indeg[j]++;
		}
	}
}

int main(){
	while(getline(cin,s1)&&getline(cin,s2)){
		stringstream input1(s1),input2(s2);
		cnt = 0;
		memset(s,0,sizeof(s));
		memset(g,0,sizeof(g));
		memset(indeg,0,sizeof(indeg));
		while(input1>>u){
			s[u[0]-'a']++;
			cnt++;
		}
		while(input2>>u&&input2>>v){
			g[u[0]-'a'][v[0]-'a'] = 1;
			indeg[v[0]-'a']++;
		}
		dfs(1);
		cout<<endl;
	}
	
	return 0; 
} 
