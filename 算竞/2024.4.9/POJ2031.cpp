#include<bits/stdc++.h>
#define S(x) ((x)*(x))
using namespace std;

struct Data{
	double x,y,z,r;	
}d[105];
struct Dis{
	int a,b;
	double d;
	bool operator<(const Dis& b)const{
		return d<b.d;
	}
}dis[100005];
int n,cnt,fa[105];

double ans;

double DIS(int a,int b){
	return sqrt(S(d[a].x-d[b].x)+S(d[a].y-d[b].y)+S(d[a].z-d[b].z))-d[a].r-d[b].r<=0.0?
	0.0:sqrt(S(d[a].x-d[b].x)+S(d[a].y-d[b].y)+S(d[a].z-d[b].z))-d[a].r-d[b].r;			   
}

int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}

int merge(int a,int b){
	int af = get(a),bf = get(b);
	if(af==bf)return 0;
	fa[af] = bf;
	return 1;
}

int main(){
	while(cin>>n&&n){
		for(int i = 1;i<=n;i++){
			cin>>d[i].x>>d[i].y>>d[i].z>>d[i].r;
			fa[i] = i;
		}
		cnt = 0;
		
		for(int i = 1;i<=n;i++){
			for(int j =1;j<=n;j++){
				dis[++cnt].d = DIS(i,j);	
				dis[cnt].a=i;
				dis[cnt].b=j;	
			}
		}	
		ans = 0.0;		
		sort(dis+1,dis+1+cnt);
		for(int i = 1;i<=cnt;i++){
			if(merge(dis[i].a,dis[i].b)){
				ans+=dis[i].d;
				n--;
				if(n==1)break;
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
