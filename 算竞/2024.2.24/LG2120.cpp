#include<iostream>

using namespace std;


long long n,head=0,tail=0;
long long x[1000005];
long long dp[1000005];
long long s[1000005];
long long t[1000005]; 
long long c[1000005];
long long f[1000005];
long long q[1000005];


void set(long long i,long long j){
	dp[i]=dp[j]+x[i]*(s[i]-s[j])-(t[i]-t[j])+c[i];
	f[i]=dp[i]+t[i];
}

int main(){
	cin>>n;	
	for(long long i = 1;i<=n;i++){
		cin>>x[i]>>s[i]>>c[i];
		t[i]=t[i-1]+x[i]*s[i];
		s[i]+=s[i-1];
	}
	set(1,0);
	q[tail++]=0;
	q[tail++]=1;
	for(long long i = 2;i<=n;i++){
		do{
			long long X = s[q[head+1]]-s[q[head]];
			long long Y = f[q[head+1]]-f[q[head]];
			if(tail-head>=2&&Y<x[i]*X)++head;
			else break;
		}while(1);
		set(i,q[head]);
		do {
            long long A = f[i] - f[q[tail - 1]];
            long long B = f[q[tail - 1]] - f[q[tail - 2]];
            long long C = s[i] - s[q[tail - 1]];
            long long D = s[q[tail - 1]] - s[q[tail - 2]];
            if (tail - head >= 2 && A * D < B * C) --tail;
            else break;
        } while (1);
		q[tail++]=i;
	}
	long long ans = dp[n];
	for(long long i = n-1;i>=1&&s[i]==s[i+1];i--){
		ans = min(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
