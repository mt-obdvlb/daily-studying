#include<iostream>
using namespace std;
int n,m,ans=0;
char s[10000006];

int main(){
	cin>>n>>m;
	scanf("%s",s+1);
	for(int l = 1;l<=m;l++){
		for(int r = l;r<=m;r++){
			int op = 1;
			for(int k = n;op&&k>=1;k--){
				int flag = 1;
				int x = k;
				for(int i=l;flag&&i<=r;i++){
					if(s[i]=='L'){
						if(x==1)continue;
						x-=1;
					}else{
						if(x==n)flag=0;
						x+=1;
					}
				}
				if(flag){
					ans+=k;
					ans%=1000000007;
					op=0;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
