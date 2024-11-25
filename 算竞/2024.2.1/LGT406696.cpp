#include<bits/stdc++.h>

using namespace std;

int n,q,C = 0; 
int vis[200005]={0};
int cnt[200005]={0};
int ans[200005]={0};

int main(){
	scanf("%d%d",&n,&q);
	for(int c,l,r,k,i = 0;i<q;i++){
		scanf("%d",&c);
		switch(c){
			case 1:
				scanf("%d%d%d",&l,&r,&k);
				for(int j = l;j<=r;j++){
					if(vis[j])continue;
					if(cnt[j]>=0)cnt[j]+=k;
					else cnt[j]=k;
				}
				for(int j = 1;j<l;j++){
					if(vis[j])continue;
					if(cnt[j]<=0)cnt[j]-=k;
					else cnt[j]=-k;
				}
				for(int j = r+1;j<=n;j++){
					if(vis[j])continue;		
					if(cnt[j]<=0)cnt[j]-=k;
					else cnt[j]=-k;
				}
				break;
			case 2:
				scanf("%d%d%d",&l,&r,&k);
				for(int j = l;j<=r;j++){
					if(vis[j])continue;
					if(cnt[j]>=k||cnt[j]<=-k){
						n--;
						vis[j]=1;
					}
				}
				break;
			case 3:
				ans[C++]=n;
				break;
		}
	}
	for(int i = 0;i<C;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
