#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int n,m,ans,minv[10005],mins[10005];

void init(){
    minv[0]=mins[0]=0;
    for(int i=1;i<22;i++){
        minv[i]=minv[i-1]+i*i*i;
        mins[i]=mins[i-1]+2*i*i;
    }
}

void dfs(int dep,int sumv,int sums,int r,int h){
	if(!dep){
		if(sumv==n)ans = min(ans,sums);
		return;
	}
	if(sumv+minv[dep]>n||sums+mins[dep]>ans||sums+2*(n-sumv)/r>ans) return;
	for(int i = r;i>=dep;i--){
		if(dep==m)sums = i*i;
		int maxh = min(h,(n-sumv-minv[dep-1])/(i*i));
		for(int j = maxh;j>=dep;j--){
			dfs(dep-1,sumv+i*i*j,sums+2*i*j,i-1,j-1);
		}
	}
}

int main(){
	cin>>n>>m;
	ans = INF;
	dfs(m,0,0,n,n);
	cout<<(ans==INF?0:ans)<<endl;
	return 0;
}
