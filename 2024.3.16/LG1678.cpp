#include<iostream>
#include<algorithm>
using namespace std;

int m,n;
int a[100005];

int main(){
	cin>>m>>n;
	for(int i = 0;i<m;i++){
		scanf("%d",a+i);
	}
	sort(a,a+m);
	long long ans = 0;
	while(n--){
		int b;
		scanf("%d",&b);
		int l = 0,r = m-1,mid;
		while(l<r){
			mid = (l+r)/2;
			if(a[mid]>b){
				r = mid;
			}else{
				l = mid+1;
			}
		}
		if(l==0){
			ans+=abs(b-a[l]);
		}else{
			ans+=min(abs(b-a[l]),abs(b-a[l-1]));
		}
		
	
	}
	cout<<ans<<endl;
	return 0;
}
