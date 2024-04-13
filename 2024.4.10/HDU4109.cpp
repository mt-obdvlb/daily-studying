#include<bits/stdc++.h>

using namespace std;

int n,cnt,m,g[1005][1005],d[1005],indeg[1005];

void TopoSort(){
	stack<int> s;
	for(int i = 0;i<n;i++){
		if(!indeg[i]){
			s.push(i);
			d[i]=1;
		}
	}
	while(!s.empty()){
		int i = s.top();
		s.pop();
		for(int j = 0;j<n;j++){
			if(g[i][j]){
				d[j]=max(d[j],d[i]+g[i][j]);
				indeg[j]--;
				if(!indeg[j])s.push(j);
			}
		}
	}
}

int main(){
	while(cin>>n>>m){
		memset(g,0,sizeof(g));
		memset(d,0,sizeof(d));
		memset(d,0,sizeof(indeg));
		int x,y,z;
		while(m--){
			cin>>x>>y>>z;
			g[x][y]=z;
			indeg[y]++;
		}
		TopoSort();
		int ans = 0;
		for(int i = 0;i<n;i++)ans =max(ans,d[i]);
		cout<<ans<<endl;
	}
	return 0;
} 
