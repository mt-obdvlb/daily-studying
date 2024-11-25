#include<bits/stdc++.h>

using namespace std;
const int N = 1e3;
int c[N][N];
int n;
int lowbit(int i){
	return i&(-i);
}

void add(int x,int y,int t){
	for(;x<=n;x+=lowbit(x))
		for(;y<=n;y+=lowbit(y))
			c[x][y]+=t;
}

int sum(int x,int y){
	int res = 0;
	for(;x>0;x-=lowbit(x))
		for(;y>0;y-=lowbit(y))
			res += c[x][y];
	return res;
}

int sum(int x1,int y1,int x2,int y2){
	return sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);
}

int main(){
	
	return 0;
}
