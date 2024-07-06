#include<bits/stdc++.h>

using namespace std;
const int N = 6e5+5;
int n,m,cnt;
int dx[N],rt[N],maxs[N*24],t[N*24][2];

void ins(int x,int k,int i,int j){
	maxs[i]=x;
	if(k<0)return;
	int c = dx[x]>>k&1;
	if(j)t[i][c^1]=t[j][c^1];
	t[i][c]=++cnt;
	ins(x,k-1,t[i][c],t[j][c]);
}

int query(int i,int k,int val,int limit){
	if(k<0)return dx[maxs[i]]^val;
	int c = val>>k&1;
	if(maxs[t[i][c^1]]>=limit)return query(t[i][c^1],k-1,val,limit);
	else return query(t[i][c],k-1,val,limit);
}

int main(){
	scanf("%d%d",&n,&m);
	int x,l,r;
	char opt[2];
	maxs[0]=-1;
	rt[0]=++cnt;
	ins(0,23,rt[0],0);
	for(int i = 1;i<=n;i++){
		scanf("%d",&x);
		dx[i] = dx[i-1]^x;
		rt[i]=++cnt;
		ins(i,23,rt[i],rt[i-1]);
	}
	while(m--){
		scanf("%s",opt);
		if(opt[0]=='A'){
			scanf("%d",&x);
			rt[++n]= ++cnt;
			dx[n]=dx[n-1]^x;
			ins(n,23,rt[n],rt[n-1]);
		}else{
			scanf("%d%d%d",&l,&r,&x);
			printf("%d\n",query(rt[r-1],23,x^dx[n],l-1));
		}
	}
	return 0;
}
