#include<bits/stdc++.h>

using namespace std;

int n,ans,b,c;

int main(){
	cin>>n;
	while(n--){
		scanf("%d%d%d",&ans,&b,&c);
		if((b%3==2&&c==0)||(b%3==1&&c<2))printf("-1\n");
		else{
			ans+= (b+c)/3;
			ans+= ((b+c)%3?1:0);
			printf("%d\n",ans);
		}
	}
	
	return 0;
}
