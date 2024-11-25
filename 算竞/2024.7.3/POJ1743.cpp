#include<iostream>
using namespace std;

const int N = 2e4+10;
int n,a[N],sa[N],x[N],y[N],wv[N],c[N];
int rk[N],hei[N],ss[N];

int cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(int *r,int *sa,int n,int m){
	int i,k,p;
	for(i = 0;i<m;i++)c[i]=0;
	for(i = 0;i<n;i++)c[x[i]=r[i]]++;
	for(i = 1;i<m;i++)c[i]+=c[i-1];
	for(i = n-1;i>=0;i--)sa[--c[x[i]]]=i;
	for(k = 1;k<=n;k<<=1){
		p = 0;
		for(i = n-k;i<n;i++)y[p++]=i;
		for(i = 0;i<n;i++)
			if(sa[i]>=k)y[p++]=sa[i]-k;
		for(i = 0;i<n;i++)wv[i]=x[y[i]];
		for(i = 0;i<m;i++)c[i]=0;
		for(i = 0;i<n;i++)c[wv[i]]++;
		for(i = 1;i<m;i++)c[i]+=c[i-1];
		for(i = 0;i<n;i++)sa[--c[wv[i]]]=y[i];
		
		swap(x,y);
		p = 1, x[sa[0]]=0;
		for(i = 1;i<n;i++)x[sa[i]]=cmp(y,sa[i-1],sa[i],k)?p-1:p++;
		if(p>=n)break;
		m = p;
	}
}

void calhei(int* r,int n){
	int i,j,k = 0;
	for(i = 1;i<=n;i++)rk[sa[i]]=i;
	for(i = 0;i<n;i++){
		if(k)k--;
		j = sa[rk[i]-1];
		while(r[i+k]==r[j+k])k++;
		hei[rk[i]]=k;
	}
}

bool check(int mid){
	int mx=sa[1],mn = sa[1];
	for(int i = 2;i<=n;i++){
		if(hei[i]>=mid){
			mx = max(mx,sa[i]);
			mn = min(mn,sa[i]);
			if(mx-mn>=mid)return 1;
		}else{
			mx = sa[i];
			mn = sa[i];
		}
	}
	return 0;
}

void solve(){
	int l = 4,r = n,mid,ans=-1;
	while(l<=r){
		mid = (l+r)>>1;
		if(check(mid)){
			ans = mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	} 
	if(ans<4)cout<<0<<endl;
	else cout<<ans+1<<endl;
}

int main(){
	while(cin>>n&&n){
		int mx = 0;
		for(int i = 0;i<n;i++){
			scanf("%d",a+i);		
			mx = max(mx,a[i]);
		}
		n--;
		for(int i = 0;i<n;i++)ss[i]=a[i+1]-a[i]+100;
		ss[n]=0;
		da(ss,sa,n+1,200);
		calhei(ss,n);
		solve();
	}
	return 0;
} 
