#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
typedef long long ll;
ll a[N],sum[N],add[N];
int L[N],R[N],d;
int pos[N];
int n,m,t,l,r;
char op[3];

void build(){
	t = sqrt(n*1.0);
	int num = n/t;
	if(n%t)num++;
	for(int i = 1;i<=num;i++){
		L[i] = (i-1)*t+1;
		R[i] = i*t;
	}
	R[num] = n;
	for(int i = 1;i<=num;i++){
		for(int j = L[i];j<=R[i];j++){
			pos[j] = i;
			sum[i]+=a[j]; 
		}
	}
}

void change(int l,int r,ll d){
	int p = pos[l],q = pos[r];
	if(p==q){
		for(int i = l;i<=r;i++){
			a[i]+=d;
		}
		sum[p]+=d*(r-l+1);
		return;
	}
	for(int i = p+1;i<=q-1;i++){
		add[i]+=d; 
	}
	for(int i = l;i<=R[p];i++)a[i]+=d;
	sum[p]+=d*(R[p]-l+1);
	for(int i = L[q];i<=r;i++){
		a[i]+=d;
	}
	sum[q]+=d*(r-L[q]+1);
}

ll query(int l,int r){
	int p = pos[l],q = pos[r];
	ll ans = 0;
	if(p==q){
		for(int i = l;i<=r;i++)ans+=a[i];
		ans+=add[p]*(r-l+1);
		return ans;
	}
	for(int i = p+1;i<=q-1;i++)ans+=sum[i]+add[i]*(R[i]-L[i]+1);
	for(int i = l;i<=R[p];i++)ans+=a[i];
	ans+=add[p]*(R[p]-l+1);
	for(int i = L[q];i<=r;i++)ans+=a[i];
	ans+=add[q]*(r-L[q]+1);
	return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(); 
    for(int i=1;i<=m;i++){
        scanf("%s %d %d",op,&l,&r);
        if(op[0]=='C'){
            scanf("%d",&d);
            change(l,r,d);
        }
        else
			printf("%lld\n",query(l,r));
    }
    return 0;
}
