#include<iostream>
#include<cmath>

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 5e4+5;
int n,q;
int a[N],L[N],R[N],ind[N],Max[N],Min[N];

void build(){
	int t = (int)sqrt((double)n);
	int num = n/t;
	if(n%t)num++;
	for(int i = 1;i<=n;i++){
		L[i] = (i-1)*t+1;
		R[i] = i*t; 
	}
	R[num] = n;
	for(int i = 1;i<=num;i++){
		Max[i] = -1,Min[i] = inf;
		for(int j = L[i];j<=R[i];j++){
			ind[j] = i;
			Max[i] = max(Max[i],a[j]);
			Min[i] = min(Min[i],a[j]);
		}
	}
}

int query(int l,int r){
	int p = ind[l],q = ind[r];
	int mi = 0x3f3f3f3f,ma = -1;
	if(p==q){
		for(int i = l;i<=r;i++){
			ma = max(ma,a[i]);
			mi = min(mi,a[i]);
		}
		return ma-mi;
	}
	for(int i = p+1;i<=q-1;i++){
		ma = max(ma,Max[i]);
		mi = min(mi,Min[i]);
	}
	for(int i = l;i<=R[p];i++){
		ma = max(ma,a[i]);
		mi = min(mi,a[i]);
	}
	for(int i = L[q];i<=r;i++){
		ma = max(ma,a[i]);
		mi = min(mi,a[i]);
	}
	return ma-mi;
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i = 1;i<=n;i++){
		scanf("%d",a+i);		
	}
	build();
	int l,r;
	while(q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}
