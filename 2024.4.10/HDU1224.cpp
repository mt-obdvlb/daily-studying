#include<bits/stdc++.h>

using namespace std;

int T,n,m,cnt,g[105][105],d[105],a[105],ans[105],pre[105];

void dfs(){
	
}

int main(){
	cin>>T;
	for(int TT = 1;TT<=T;TT++){
		memset(g,0,sizeof(g));
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		memset(pre,0,sizeof(pre));
		memset(ans,0,sizeof(pre));
		cnt = 0;
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>d[i];
		}
		a[1] = d[n+1]=d[1];
		cin>>m;
		for(int i = 0;i<m;i++){
			int a,b;
			cin>>a>>b;
			g[a][b] = 1;
		}
		for(int i = 1;i<=n+1;i++){
			for(int j = 1;j<=n+1;j++){
				if(!g[i][j])continue;
				if(a[j]<a[i]+d[j]){
					a[j] = a[i]+d[j];
					pre[j] =i;
				}
			}
		}
		int cur = n+1;
		while(cur!=1){
			ans[cnt++]=cur;
			cur = pre[cur];
		}
		printf("CASE %d#\n",TT);
		printf("points : %d\n",a[n+1]);
		printf("circuit : ");
		cout<<1<<"->";
		for(int i = cnt-1;i>=1;i--){
			cout<<ans[i]<<"->";
		}
		cout<<1;
		cout<<endl<<endl;
	}
	return 0;
}
