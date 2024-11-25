#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int l[1000005],r[1000005],v[1000005];
int ans[1000005]={0},ind[1000005]={0},q[1000005]={0};

int main(){
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		scanf("%d%d%d",l+i,r+i,v+i);
		ind[i]=i;
	}
	sort(ind+1,ind+1+m,[&](int i,int j)->bool{
		if(r[i]!=r[j])return r[i]<r[j];
		return v[i]>v[j];
	});
	
	for(int i = 1,j=1;i<=n;i++){
		if(i!=r[ind[j]])continue;
		ans[i]=v[ind[j]]-q[ind[j]];
		for(int k = j;k<=m;k++){
			if(l[ind[k]]>i)break;
			q[ind[k]]+=ans[i];
			if(r[ind[k]]==i)j++;
		}
	}
	for(int i = 1;i<=n;i++){
		if(i!=1)printf(" ");
		printf("%d",ans[i]);
	}
	return 0;
}
