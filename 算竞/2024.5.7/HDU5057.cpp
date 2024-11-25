#include<iostream>
#include<cmath>

using namespace std;

const int N =1e5+5;
const int Num = 4e2+5;
int T;
int n,m;
int L[N],R[N],cnt[Num][13][13];
int ind[N],a[N];

int ten[11]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

void build(){
	int t = sqrt(n);
	int num = n/t;
	if(n%t)num++;
	for(int i = 1;i<=num;i++){
		L[i] = (i-1)*t +1;
		R[i] = i*t;
	}
	R[num] = n;
	for(int i = 1;i<=n;i++){
		ind[i] = (i-1)/t +1;
	}
	int tmp;
	for(int i = 1;i<=n;i++){
		tmp = a[i];
		for(int j = 1;j<=10;j++,tmp/=10){
			cnt[ind[i]][j][tmp%10]++;
		}
	}
}

int query(int l,int r,int d,int p){
	int tot = 0;
	int i1 = ind[l],i2 = ind[r];
	if(i1==i2){
		for(int i = l;i<=r;i++){
			if(a[i]/ten[d]%10==p)tot++;
		}
		return tot;
	}
	for(int i = i1+1;i<=i2-1;i++){
		tot+=cnt[i][d][p];
	}
	for(int i = l;i<=R[i1];i++){
		if(a[i]/ten[d]%10==p)tot++;
	}
	for(int i = L[i2];i<=r;i++){
		if(a[i]/ten[d]%10==p)tot++;
	}
	return tot;
}


int main(){
	scanf("%d",&T);
	char opt[2];
	int x,y,l,r,d,p;
	while(T--){
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d",&n,&m);
		for(int i = 1;i<=n;i++){
			scanf("%d",&a[i]);			
		}
		build();
		while(m--){
			scanf("%s",opt);
			if(opt[0]=='S'){
				scanf("%d%d",&x,&y);
				for(int i = 1;i<=10;i++,a[x]/=10){
					cnt[ind[x]][i][a[x]%10]--;
				}
				a[x] = y;
				for(int i = 1;i<=10;i++,y/=10){
					cnt[ind[x]][i][y%10]++;
				}
			}else{
				scanf("%d%d%d%d",&l,&r,&d,&p);
				printf("%d\n",query(l,r,d,p));
			}
		}
	}
	return 0;
}
