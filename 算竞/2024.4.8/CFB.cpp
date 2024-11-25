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

long long t,n,c,d,flag,a[505][505];
multiset<long long>::iterator it;

int main(){
	cin>>t;
	while(t--){
		scanf("%lld%lld%lld",&n,&c,&d);
		memset(a,0,sizeof(a));
		multiset<long long> s;
		for(int i = 1;i<=n*n;i++){
			long long tmp;
			scanf("%lld",&tmp);
			s.insert(tmp);
		}
		a[1][1] = *s.begin();
		flag =1;
		for(int i = 1;flag&&i<n;i++){
			for(int j = 1;flag&&j<n;j++){
				a[i+1][j] = a[i][j]+c;
				a[i][j+1] = a[i][j]+d;
				a[i+1][j+1] = a[i][j] +d+c; 
			}
		}
		for(int i = 1;flag&&i<=n;i++){
			for(int j = 1;flag&&j<=n;j++){
				it = lower_bound(s.begin(),s.end(),a[i][j]);
				//cout<<*it;
				if(it==s.end()||*it != a[i][j]){
					flag = 0;
					break;
				}
				s.erase(it);
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
