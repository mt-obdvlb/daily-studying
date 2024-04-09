#include<bits/stdc++.h>

using namespace std;

char g[4000][4000];
int n,m,i,j,sum,len[20],pos[20],h[20];

void draw(int x,int y,int d){
	g[x][y] = 'o';
	if(d==1)return;
	int lx = x+1,ly = y-1,rx = x+1,ry = y+1;
	for(int i = 1;i<=len[d-1];i++){
		g[lx][ly] = '/';
		g[rx][ry] = '\\';
		lx = lx+1,ly = ly-1,rx = rx+1,ry = ry+1;
	}
	draw(lx,ly,d-1);
	draw(rx,ry,d-1);
}

void erase(int x,int y){
	g[x][y] = ' ';
	if(g[x-1][y-1] == '\\') erase(x-1,y-1);         //左上角
    if(g[x-1][y+1] == '/') erase(x-1,y+1);          //右上角
    if(g[x+1][y-1] == '/' || g[x+1][y-1] == 'o') erase(x+1,y-1); //左下角，因为往下还要删除孩子节点，要多一个判断
    if(g[x+1][y+1] == '\\'|| g[x+1][y+1] == 'o') erase(x+1,y+1); //右下角同理
}

int main(){
	cin>>m>>n;
	len[1]=1,pos[1]=1;
	sum = 1;
	for(int i = 2;i<=m;i++){
		len[i] = sum + i-1;
		sum+=len[i];
		pos[i] = len[i]+1;
	}
	h[m] = 1;
	for(int i = m - 1;i;i--)h[i]=h[i+1]+len[i]+1;
	memset(g,' ',sizeof(g));
	draw(1,pos[m],m);
	while(n--){
		cin>>i>>j;
		if(i>10)continue;
		int x = h[m+1-i],y;
		if(i==m){
			if(j&1)y = pos[1] +j/2*6;
			else y = pos[1]+j/2*6-2;
		}else y = pos[m+1-i]+(j-1)*(2*len[m+1-i]+2);
		erase(x,y);
	}
	int hei = h[1],w = 6*(1<<(m-1));
	for(int i = 1;i<=hei;i++){
		for(int j = 1;j<=w;j++)printf("%c",g[i][j]);
		printf("\n");
	}
	return 0;
}
