#include<bits/stdc++.h>

using namespace std;

#define S(x) ((x)*(x))


long long n,M;
long long C[1000005]={0},f[1000005];
long long dp[1000005]={0},q[1000005];
long long head=0,tail = 0;

double calu(long long i,long long j){
	return 1.0*(f[i]-f[j])/(C[i]-C[j]);
}

void _set(long long i, long long j) {
    dp[i] = dp[j] + S(C[i] - C[j]) + M;
    f[i] = dp[i] + S(C[i]);
    return ;
}

int main(){
	scanf("%lld%lld",&n,&M);
	for(long long c,i = 1;i<=n;i++){
		scanf("%lld",C+i);
		C[i]+=C[i-1];		
	}
	q[tail++]=0;
	for(long long i = 1;i<=n;i++){
		while((tail-head)>=2&&calu(q[head+1],q[head])<2*C[i])head++;
		_set(i, q[head]);
		while((tail-head)>=2&&calu(i, q[tail - 1])<calu(q[tail - 1], q[tail - 2]))tail--;
		q[tail++]=i;
	}
	printf("%lld\n",dp[n]);
	return 0;
}
