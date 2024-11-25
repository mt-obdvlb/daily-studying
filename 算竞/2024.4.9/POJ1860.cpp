#include<bits/stdc++.h>

using namespace std;

int n,m,s,cnt;
struct edge{
	int a,b;
	double r,c;
}e[105];
double cm,r,c;
double dis[105];



void add(int a,int b,double r,double c){
	e[++cnt].a =a;
	e[cnt].b =b;
	e[cnt].r =r;
	e[cnt].c =c;
}

bool BF(){
	dis[s] = cm;
	for(int i = 1;i<n;i++){
		bool flag = 0;
		for(int j = 1;j<=cnt;j++){
			if(dis[e[j].b]<(dis[e[j].a]-e[j].c)*e[j].r){
				flag = 1;
				dis[e[j].b]	=(dis[e[j].a]-e[j].c)*e[j].r;
			}		
		}		
		if(!flag)return false;
	}
	bool flag = 0;
	for(int j = 1;j<=cnt;j++){
		if(dis[e[j].b]<(dis[e[j].a]-e[j].c)*e[j].r){
			flag = 1;
			dis[e[j].b]	=(dis[e[j].a]-e[j].c)*e[j].r;
		}		
	}		
	if(flag)return true;
	return false;
}

int main(){
	cin>>n>>m>>s>>cm;
	int a,b;
	while(m--){
		cin>>a>>b;
		cin>>r>>c;
		add(a,b,r,c);
		cin>>r>>c;
		add(b,a,r,c);
	} 
	if(BF())cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
