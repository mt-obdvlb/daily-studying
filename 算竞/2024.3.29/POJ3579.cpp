#include<iostream>
#include<algorithm>

using namespace std;
int arr[1000005];
int n,m;

bool check(int val){
	int cnt = 0;
	for(int i = 0;i<n;i++)cnt+=n-(lower_bound(arr,arr+n,arr[i]+val)-arr);
	return cnt>m;
}


int main(){
ios::sync_with_stdio(false);
	while(~scanf("%d",&n)){
		m = n*(n-1)/4;
		for(int i = 0;i<n;i++)scanf("%d",arr+i);
		sort(arr,arr+n);
		int l = 0,r = arr[n-1]-arr[0],mid,ans;
		while(l<=r){
			mid = (r+l)>>1;
			if(check(mid)){
				ans = mid;
				l = mid+1 ;
			}else{
				r = mid-1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
