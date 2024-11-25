#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;



#define MAX_NUM 500000
long long tmp[MAX_NUM+10]; 



long long calu(long long* arr,long long l,long long r){
	if(r-l<=1){
		return 0;
	}
	long long mid = (r+l)/2;
	long long a = calu(arr,l,mid);
	long long b = calu(arr,mid,r);
	long long c = 0;
	long long p1 = l,p2 = mid,k = 0;
	while(p1!=mid||p2!=r){
		if(p2==r||(p1!=mid&&arr[p1]<=arr[p2])){
			tmp[k++]=arr[p1++];
		}else{
			tmp[k++]=arr[p2++];
			c += mid -  p1;
		}
	}
	for(long long i = l;i<r;i++){
		arr[i] = tmp[i-l];
	}
	return a+b+c;
} 

int main(){
	long long n;
	while(~scanf("%d",&n)){
		if(n == 0){
			return 0;
		}
		long long* arr = new long long[n+10];
		for(long long i = 0;i<n;i++){
			scanf("%lld",&arr[i]);
		}
		cout<<calu(arr,0,n)<<endl;
		delete[](arr);
	}
	return 0;
}
