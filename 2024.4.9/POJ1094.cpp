#include<bits/stdc++.h>

using namespace std;

string s;
char ans[55];
int g[50][50],tmp[50],indeg[50];
int n,m;

int TS(){
	stack<int> s;
	int flag = 1;
	for(int i = 0;i<n;i++){
		tmp[i] = indeg[i];
	}
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(!tmp[i]){
			cnt++;
			s.push(i);
		}
	}	
	int tot = 0;
	if(cnt==0)return 0;
	if(cnt>1)flag=-1;
	while(!s.empty()){
		cnt = 0;
		int i = s.top();
		s.pop();
		ans[tot++] = (char)('A'+i);
		for(int j = 0;j<n;j++){
			if(!g[i][j])continue;
			tmp[j]--;
			if(!tmp[j])s.push(j),cnt++;
		}
		if(cnt>1)flag = -1;
	}
	if(tot<n)return 0;
	return flag;
}


int main(){
	while(cin>>n>>m&&n&&m){
		int sign = 0;
		memset(indeg,0,sizeof(indeg));
		memset(g,0,sizeof(g));
		for(int i =0;i<m;i++){
			cin>>s;
			if(sign)continue;
			int u = s[0]-'A';
			int v = s[s.size()-1]-'A';
			g[u][v]=1;
			indeg[v]++;	
			memset(ans,0,sizeof(ans));
			int s = TS();
			if(s==0){
				printf("Inconsistency found after %d relations.\n",i+1);
				sign = 1;
			}else if(s==1){
				printf("Sorted sequence determined after %d relations: %s.\n",i+1,ans);
				sign =1 ;
			}
		}
		if(!sign)cout<<"Sorted sequence cannot be determined."<<endl;	
	}
	return 0;
}
