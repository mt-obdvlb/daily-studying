#include<bits/stdc++.h>

using namespace std;

int T,n,m,flag,g[205][205],indeg[205],w[205];

void TS(){
	for(int i = n;i>0;i--){
		int t = -1;
		for(int j = n;j>0;j--){
			if(!indeg[j]){
				t = j;
				break;
			}
		}
		if(t==-1){
			flag = 0;
			return;
		}
		indeg[t] = -1;
		w[t] = i;
		for(int j = 1;j<=n;j++){
			if(g[t][j]){
				indeg[j]--;
			} 
		}
	}
}

int main(){
	cin>>T;
	while(T--){
		flag = 1;
		cin>>n>>m;		
		int a,b;
		memset(g,0,sizeof(g));
		memset(indeg,0,sizeof(indeg));
		for(int i = 0;i<m;i++){
			cin>>a>>b;
			if(!g[b][a]){
				g[b][a]=1;
				indeg[a]++;
			}
		}
		TS();
		if(flag){
			for(int i = 1;i<=n;i++)cout<<w[i]<<" ";
			cout<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}


