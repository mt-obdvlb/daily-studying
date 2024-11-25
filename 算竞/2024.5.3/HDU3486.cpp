#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 200005;
long long n,k,pre,ans,t;
int st[MAXN][20];

int RMQ(long l,int r){
	int k = log2(r-l+1);
	return max(st[l][k],st[r-(1<<k)+1][k]);	
}

int main(){
	while(cin>>n>>k&&~n&&~k){
		for(int i = 1;i<=n;i++)scanf("%d",&st[i][0]);
		for(int k = 1;k<=log2(n);k++){
			for(int i = 1;i<=n-(1<<k)+1;i++){
				st[i][k] = max(st[i][k-1],st[i+(1<<(k-1))][k-1]);
			}
		}
		int i,j=0,t,ans=0,pre=0;
	    for(i=1;i<=n;i++){
	        t=n/i;
	        if(pre!=t){//������䳤�Ⱥ��ϴ�һ�������ó�ʼ����ֱ���ۼ���һ��������ֵ���� 
	            j=0;
	            ans=0;
	        }
	        for(;j<i;j++)
	            ans+=RMQ(t*j+1,j*t+t);
	        pre=t;
	        if(ans>k) break;
	    }
	    if(i>n)
			printf("-1\n");
	    else
	    	printf("%d\n",i);
	}
	return 0;
}
