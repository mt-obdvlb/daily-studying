#include<iostream>
#include<cmath>


#define MAX_N 20
#define S(x) ((x)*(x))

using namespace std;

double ans = 1e9;
double x[MAX_N],y[MAX_N];
double dis[MAX_N][MAX_N];
double dp[70000][MAX_N] = {0};
int ind[70000];

void dfs(int t,int now,double s){
	if(t == 0){
		if(s<ans){
			ans = s;
		}
		return;
	}
	for(int k = t;k;k -= ((-k) & k )){
		int to = ind[k&(-k)],next_t = t-(1 << to);
		double l = s + dis[now][to];
		if(dp[next_t][to]!=0&&dp[next_t][to]<=l){
			continue;
		}
		dp[next_t][to] = l;
		if(l>=ans){
			continue;
		}
		dfs(next_t,to,l);
	}
}

double __dis(int i,int j){
	return sqrt(S(x[i]-x[j])+S(y[i]-y[j]));
}


int main(){
	int n = 0;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%lf%lf",x+i,y+i);
	}
	x[0] = y[0] = 0.0;
	for(int i= 0;i<=n;i++){
		for(int j = i;j<=n;j++){
			dis[i][j] = dis[j][i] = __dis(i,j);
		}
	}
	for(int i = 0;i<=n;i++){
		ind[1<<i] = i;
	}
	dfs((1<<(n+1)) - 2,0,0);
	printf("%.2lf\n",ans);
	return 0;
}
