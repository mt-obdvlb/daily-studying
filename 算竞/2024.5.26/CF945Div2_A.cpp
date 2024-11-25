#include<bits/stdc++.h>

using namespace std;

int main(){
	int T,a,b,c;
	cin>>T;
	while(T--){
		scanf("%d%d%d",&a,&b,&c);		
		if((a+b+c)&1)printf("-1\n");
		else printf("%d\n",min((a+b+c)>>1,a+b));
	}	
	return 0;
}
