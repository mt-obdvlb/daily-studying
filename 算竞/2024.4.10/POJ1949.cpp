#include<bits/stdc++.h>

using namespace std;

int n,m,g[105][105],d[105],indeg[105],el[105];

void TopoSort(){
	stack<int> s;
	for(int i = 1;i<=n;i++){
		if(!indeg[i]){
			s.push(i);
			el[i] = d[i];
		}
	}
	while(!s.empty()){
		int i = s.top();
		s.pop();
		for(int j = 1;j<=n;j++){
			if(g[i][j]){
				indeg[j]--;
				el[j] = max(el[j],el[i]+d[j]);
				if(!indeg[j]){
					s.push(j);
				}
			}
		}
	}
}

int main(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>d[i]>>m;
		int t;
		while(m--){
			cin>>t;
			g[t][i] = 1;
			indeg[i]++;
		}
	}
	
	TopoSort();
	int ans = 0;
	for(int i = 1;i<=n;i++){
		ans=max(ans,el[i]);
	}
	cout<<ans<<endl;
	return 0;
}
