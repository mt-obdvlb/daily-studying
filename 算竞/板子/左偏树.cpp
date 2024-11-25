#include<bits/stdc++.h>
#define lc l[x]
#define rc r[x]
using namespace std;
const int N = 1e4;
int fa[N],l[N],r[N],d[N],v[N],cnt,rt;

int merge(int x,int y){
	if(!x||!y)return x|y;
	if(v[x]<v[y])swap(x,y);
	rc = merge(rc,y);
	fa[rc] = x;
	if(d[lc]<d[rc]) swap(lc,rc);
	d[x] = d[rc] + 1;
	return x;
}

void pop(int x){
	fa[lc]=lc,fa[rc]=rc;
	rt = merge(lc,rc);
}

int ins(int x){
	v[++cnt]=x;
	l[cnt]=r[cnt]=d[cnt]=0;
	fa[cnt]=cnt;
	return merge(rt,cnt);
}

int main(){
	
	
	return 0;
}
