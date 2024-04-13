#include<bits/stdc++.h>

using namespace std;

bool g[105][105];
int indeg[105],vis[105];

int main(){
	int n,v;
	cin>>n;
	for(int i = 1;i<=n;i++){
		while(cin>>v&&v){
			g[i][v] = 1;
			indeg[v]++;
		}
	}
	stack<int> s;
	for(int i = 1;i<=n;i++)if(!indeg[i])s.push(i),vis[i]=1;
	while(!s.empty()){
		int cur = s.top();
		cout<<cur<<" ";
		s.pop();
		for(int i = 1;i<=n;i++){
			if(vis[i])continue;
			if(g[cur][i]){
				indeg[i]--;
				if(!indeg[i]){
					vis[i]=1;
					s.push(i);
				}
			}
		}
	}
	return 0;   
}
