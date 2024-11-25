#include<bits/stdc++.h>

using namespace std;

void radix_sort(int *a,int l,int r){
	const int K = 65536;
	int *cnt = (int*)malloc(sizeof(int)*K);
	int *tmp = (int*)malloc(sizeof(int)*(r-l+1));
	memset(cnt,0,sizeof(cnt));
	for(int i = l;i<r;i++)cnt[a[i]%K]++;
	for(int i = 1;i<K;i++)cnt[i]+=cnt[i-1];
	for(int i = r-1;i>=l;i--)tmp[--cnt[a[i]%K]]=a[i];
	memcpy(a+l,tmp,sizeof(int)*(r-l));
	memset(cnt,0,sizeof(cnt));	
	for(int i = l;i<r;i++)cnt[a[i]/K]++;
	for(int i = 1;i<K;i++)cnt[i]+=cnt[i-1];
	for(int i = r-1;i>=l;i--)tmp[--cnt[a[i]/K]]=a[i];
	memcpy(a+l,tmp,sizeof(int)*(r-l));
}

int main(){
	
	return 0;
}
