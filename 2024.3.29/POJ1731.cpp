#include<algorithm>
#include<cstdio>
#include<string>
#include<iostream>
#include<cstring> 

using namespace std;

char ans[205];

int main(){
	ios::sync_with_stdio(false);
	scanf("%s",ans);
	int n = strlen(ans);
	sort(ans,ans+n);
	do{
		printf("%s\n",ans);
	}while(next_permutation(ans,ans+n));
	return 0;
}
