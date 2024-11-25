#include<iostream>


using namespace std;

int n,r,c[1005];
double w[1005];
int vis[1005] = {0};
int fa[1005];
int cnt[1005];

int find_x(){
	int x = -1;
	for(int i = 1;i<=n;i++){
		if(vis[i]||r==i)continue;
		if(x==-1||w[x]<w[i])x = i;
	}
	return x;
}

int find_father(int x){
	if(vis[fa[x]])return find_father(fa[x]);
	return fa[x];
}

long long ans = 0;

int main(){
	cin>>n>>r;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
		w[i] = c[i];
		fa[i] = i;
		ans += c[i];
		cnt[i] = 1;
	}
	for(int a,b,i = 1;i<n;i++){
		cin>>a>>b;
		fa[b] = a;
	}
	for(int i = 1;i<n;i++){
		int x = find_x();
		int father_x = find_father(x);
		c[father_x] += c[x];
		ans += (c[x] * cnt[father_x]);
		cnt[father_x]+=cnt[x];
		vis[x] = 1;
		w[father_x] = c[father_x]*1.0/cnt[father_x];
	}
	cout<< ans <<endl;
	return 0;
}
