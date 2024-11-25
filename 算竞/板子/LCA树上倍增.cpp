#include<bits/stdc++.h>

using namespace std;
const int N =1e4;
int f[N][30],d[N];
int k,n;

void ST(){
	for(int j = 1;j<=k;j++)
		for(int i = 1;i<=n;i++)
			f[i][j] = f[f[i][j-1]][j-1];
}

int LCA(int x,int y){
	if(d[x]>d[y])swap(x,y);
	for(int i = k;i>=0;i--)
		if(d[f[y][i]]>=d[x]) y = f[y][i];
	if(x==y)return x;
	for(int i = k;i>=0;i--)
		 if(f[x][i]!=f[y][i])
		 	x = f[x][i],y = f[y][i];
	return f[x][0];
}

int main(){
	
	return 0;
}
