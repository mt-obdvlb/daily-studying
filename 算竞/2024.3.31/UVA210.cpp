#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

string ins,posts,st;
int in[10005],post[10005],min_ind;
int vis[10005],l[10005],r[10005],val[10005],ans = INF,tot = 0;


int build(int ll,int lr,int rl,int rr){
	if(ll == lr)return 0;
	int ind,cnt=0,ret = ++tot;
	val[ret] = post[rr-1];
	if(lr-ll==1){
		l[ret]=0,r[ret] = 0;
		return ret;
	}	
	for(ind = ll;ind<lr;ind++,cnt++){
		if(in[ind]==post[rr-1])break;
	}
	l[ret] = build(ll,ind,rl,rl+cnt);
	r[ret] = build(ind+1,lr,rl+cnt,rr-1);
	return ret;
}

void dfs(int o,int v){
	if(o==0)return;
	vis[o] = 1;
	v+=val[o];
	if(l[o]==0&&r[o]==0){
		if(v<ans){
			ans = v;
			min_ind = o;
		}
		vis[o]=0;
		return;
	}
	if(vis[l[o]]==0&&l[o])dfs(l[o],v);
	if(vis[r[o]]==0&&r[o])dfs(r[o],v);
	vis[o]=0;	
}

int main(){
	
	while(getline(cin,ins)&&getline(cin,posts)){
		memset(vis,0,sizeof(vis));
		memset(l,0,sizeof(vis));
		memset(r,0,sizeof(vis));
		memset(in,0,sizeof(vis));
		memset(post,0,sizeof(vis));
		memset(val,0,sizeof(val));
		ans = INF;
		stringstream input1(ins),input2(posts);
		tot = 0;
		while(input1>>st)in[tot++]=stoi(st);
		tot = 0;
		while(input2>>st)post[tot++]=stoi(st);
		int n = tot;
		tot = 0;
		int rt = build(0,n,0,n);
		dfs(rt,0);
		cout<<val[min_ind]<<endl;
	}
	return 0;
}
