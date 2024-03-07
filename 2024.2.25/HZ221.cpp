#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int a[100005],h[100005];
int ind[100005],ans[100005]={0};



int main(){
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		scanf("%d",a+i);	
		ind[i]=i;
	}
	for(int i = 0;i<m;i++)scanf("%d",h+i);
	sort(ind,ind+n,[&](int i,int j)->bool{
		return a[i]<a[j];
	});
	sort(h,h+m);
	for(int i = 0,j = 0;j<m&&i<n;i++){
		if(a[ind[i]]<h[j])continue;
		int l = j,r = m-1,mid=(l+r)/2;
		while(l<r){
			if(h[mid]==a[ind[i]])break;
			else if(h[mid]>a[ind[i]]){
				r = mid-1;
			}else{
				l = mid;
			}
			mid=(l+r+1)/2;
		}
		ans[ind[i]]+=mid-j+1;
		j = mid+1;
	}
	for(int i = 0;i<n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
