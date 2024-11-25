#include<bits/stdc++.h>

using namespace std;
const int N = 4e4+10;
int k,x[N],y[N],c[30],r[N],sa[N],hei[N],rk[N];
int wv[N];


int cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(int n,int m){
	int i,p,k;
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
		for(i=1;i<m;i++)c[i]+=c[i-1];
		for(i = n-1;i>=0;i--)sa[--c[wv[i]]]=y[i];
		swap(x,y);
		p = 1,x[sa[0]]=0;
		for(i = 1;i<n;i++)x[sa[i]]=cmp(y,sa[i-1],sa[i],k)?p-1:p++;
		if(p>=n)break;
		m = p;
	}
}

void calhei(int n){
	int k = 0,j;
	for(int i = 1;i<=n;i++)rk[sa[i]]=i;
	for(int i = 0;i<n;i++){
		if(k)k--;
		j = sa[rk[i]-1];
		while(r[i+k]==r[j+k])k++;
		hei[rk[i]]=k; 
	}
}

int check(int x,int n){
	int cnt = 1,tmp = sa[1],ans = -1;
	for(int i = 1;i<=n;i++){
		if(hei[i]<x){
			cnt = 1;
			tmp = sa[i];
		}else{
			cnt++;
			tmp = max(tmp,sa[i]);
		}
		if(cnt>=k)ans = max(ans,tmp);
	}
	return ans;
} 

void solve(int n){
	int l = 1,mx,r = n,res = -1,ans = -1;
	while(l<=r){
		int mid = (l+r)>>1;
		mx = check(mid,n);
		if(~mx){
			res = mid;
			ans = mx;
			l = mid+1; 
		}else{
			r = mid-1;
		}
		
	} 
	if(~ans)cout<<res<<" "<<ans<<endl;
	else cout<<"none"<<endl;
}

int main(){
	string s;
	while(cin>>k&&k){
		cin>>s;
		int n = s.size();
		if(k==1){
			cout<<n<<" 0"<<endl;
			continue;
		}
		for(int i = 0;i<n;i++){
			r[i] = s[i]-'a'+1;
		}
		r[n]=0;
		da(n+1,30);
		calhei(n);
		solve(n);
	}	
	return 0;
}
