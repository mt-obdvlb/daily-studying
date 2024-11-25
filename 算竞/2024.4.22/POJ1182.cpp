#include<bits/stdc++.h>

using namespace std;

const int MAXN = 50005;
int fa[MAXN],d[MAXN];
int n,k,ans;

int get(int x){
	int af = fa[x];
	if(af==x)return af;
	fa[x] = get(af);
	d[x] = (d[x]+d[af]+3)%3;
	return fa[x];
}

int main(){
	cin>>n>>k;
	for(int i = 0;i<MAXN;i++)fa[i]=i;
	while(k--){
		int c,x,y;
		cin>>c>>x>>y;
		if(x>n||y>n||(x==y&&c==2)){
			ans++;
			continue;
		}else{
			int fx = get(x),fy = get(y);			
			if(fx==fy){
				if((d[x]-d[y]+3)%3!=c-1)ans++;
			}else{
				fa[fx] = fy;
				d[fx] = (d[y]-d[x]+3+c-1)%3;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
