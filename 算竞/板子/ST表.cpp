#include<bits/stdc++.h>

using namespace std;
int st[50000][20];
int lb[50000],a[50000];
int n;

void init(){
	lb[0]=-1;
	for(int i = 1;i<50000;i++){
		lb[i]=i&(i-1)?lb[i-1]:lb[i-1]+1;
	}
}

void build_st(){
	for(int i = 1;i<=n;i++)st[i][0]=a[i];
	int k = log2(n);
	for(int j = 1;j<=k;j<<=1){
		for(int i = 1;i<=n-(1<<j)+1;i++){
			st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j]);
		}
	}
}

int query(int l,int r){
	int k = log2(r-l+1);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}

int main(){
	
	
	return 0;
}
