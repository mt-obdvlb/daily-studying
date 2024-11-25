#include<bits/stdc++.h>

using namespace std;
const int N = 1e4;
int wv[N],x[N],y[N],c[N],sa[N],h[N],rk[N];
void da(int *r,int n,int m){
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
		for(i = 0;i < n;i++)wv[i]=x[y[i]];
		for(i = 0;i<m;i++)c[i]=0;
		for(i = 0;i<n;i++)c[wv[i]]++;
		for(i = 1;i<m;i++)c[i]+=c[i-1];
		for(i = n-1;i>=0;i--)sa[--c[wv[i]]]=y[i];
		swap(x,y);
		p = 1;
		x[sa[0]]=0;
		for(i = 1;i<n;i++)
			x[sa[i]] = (y[sa[i]]==y[sa[i-1]])&&(y[sa[i]+k]==y[sa[i-1]+k])?p-1:p++;
		if(p>=n)break;
		m = p;
	}
}

void calhei(int *r,int n){
	int k = 0;
	for(int i = 1;i<=n;i++)rk[sa[i]]=i;
	for(int i = 0;i<n;i++){
		if(k)k--;
		int j = sa[rk[i]-1];
		while(r[i+k]==r[j+k])k++;
		h[rk[i]]=k;
	}
}

int main(){
	
	
	return 0;
}
