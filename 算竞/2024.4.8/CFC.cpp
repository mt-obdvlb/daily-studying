#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

inline int read(){
	int flag = 1;
	int ret = 0;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')flag = -1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret = ret * 10 + ch - '0';
		ch  = getchar(); 
	}
	return ret*flag;
}

long long T,n,k,a[200005],b[200005];

int main(){
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i = 0;i<n;i+=2){
			scanf("%d",a+i);
		}
		for(int i = (n&1?n-2:n-1);i>=0;i-=2){
			scanf("%d",a+i);
		}
		b[0] = a[0];
		for(int i= 1;i<n;i++){
			b[i] = b[i-1]+a[i];
		}
		int ind = lower_bound(b,b+n,k)-b;
		if(b[ind]==k)printf("%d\n",ind+1);
		else printf("%d\n",ind);
	}
	return 0;
} 
