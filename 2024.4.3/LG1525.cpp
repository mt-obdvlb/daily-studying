#include<bits/stdc++.h>

using namespace std;

int fa[20005],val[20005];

int get(int x){
	if(fa[x]==x)return x;
	int rt = get(fa[x]);
	val[x] = (val[x]+val[fa[x]]+2)%2;
	return fa[x] = rt;
} 

void merge(int a,int b,int t){
	int af = get(a),bf = get(b);
	if(af==bf)return;
	val[af] = (t+val[b]+2-val[a])%2;
	fa[af] = bf;
}


struct Data{
	int a,b,c;
}d[100005];

int n,m;

int main(){
	for(int i = 0;i<20005;i++)fa[i]=i,val[i]=0;
	scanf("%d%d",&n,&m);
	for(int i = 0;i<m;i++){
		scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
	}
	sort(d,d+m,[&](const Data& da,const Data& db)->bool{
		return da.c>db.c;
	});
	for(int i = 0;i<m;i++){
		int a = d[i].a,b=d[i].b,c=d[i].c;
		if(get(a)==get(b)){
			if((val[a]+val[b])%2==0){
				printf("%d\n",c);
				return 0;
			}
		}else{
			merge(a,b,1);
		}
	}
	printf("0\n");
	return 0;
}
