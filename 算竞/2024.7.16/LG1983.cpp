#include<bits/stdc++.h>

using namespace std;
const int N = 1e3+10;
int n,m,a[N],g[N][N],indeg[N]; 
int ans = 0;

void topo(){
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(!indeg[i])q.push(i);
	}
	while(!q.empty()){
		int m = q.size();
		while(m--){
			int u = q.front();q.pop();
			for(int v = 1;v<=n;v++){
				if(!g[u][v])continue;
				if(--indeg[v]==0)q.push(v);
			}
		}
		ans++;
	}
}

int main(){
	cin>>n>>m;
	int s,t,k;
	for(int i = 0;i<m;i++){
		scanf("%d",&k);
		scanf("%d",&s);
		for(int j = 1;j<k-1;j++){
			scanf("%d",a+j);
		}		
		scanf("%d",&t);
		a[0]=s,a[k-1]=t;
		int tmp = 0;
		for(int j = s;j<=t;j++){
			if(j==a[tmp])tmp++;
			else{
				for(int p = 0;p<k;p++){
					if(!g[j][a[p]])indeg[a[p]]++;
					g[j][a[p]]=1;
				}
			}
		}
	}	
	topo();
	cout<<ans<<endl;
	return 0;
} 
