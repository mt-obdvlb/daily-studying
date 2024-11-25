#include<bits/stdc++.h>

using namespace std;

struct edges{
	int a,b,t;
}e[10000];

const int INF = 0x3f3f3f3f;
int f,n,m,w,s,v,t,cnt,dis[505];

void add(int a,int b,int t){
	e[++cnt].a = a;
	e[cnt].b = b;
	e[cnt].t = t;
}

bool BF(){
	memset(dis,INF,sizeof(dis));
	for(int i = 1;i<n;i++){
		bool flag = 1;
		for(int i = 1;i<=cnt;i++){
			if(dis[e[i].b]>dis[e[i].a]+e[i].t){
				flag = 0;
				dis[e[i].b] = dis[e[i].a]+e[i].t;
			}
		}
		if(flag)return false;
	}
	for(int i = 1;i<=cnt;i++){
		if(dis[e[i].b]>dis[e[i].a]+e[i].t){
			return true;				
		}
	}
	return false;
}
 


int main(){
	cin>>f;
	while(f--){
		cnt = 0;
		cin>>n>>m>>w;	
		for(int i = 2;i<=m+1;i++){
			cin>>s>>v>>t;
			add(s,v,t);
			add(v,s,t);
		}
		for(int i = 0;i<w;i++){
			cin>>s>>v>>t;
			add(s,v,-t);
		}
		if(BF())cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	return 0;
}
