#include<bits/stdc++.h>

using namespace std;

const int N = 4e4+5;
int T;
int a[N],sum[N];


int main(){
	cin>>T;
	for(int i = 1;i<N;i++){
		a[i] = a[i-1]+1+log10(i);
		sum[i] = sum[i-1]+a[i];
	}
	int n,i,pos,len,k;
	while(T--){
		cin>>n;
		i = lower_bound(sum,sum+N,n)-sum;
		pos = n - sum[i-1];
		len = k = 0;
		while(len<pos){
			k++;
			len+=(int)log10(k)+1;
		}
		cout<<k/(int)pow(10,len-pos)%10<<endl;
	}
	return 0;
}
