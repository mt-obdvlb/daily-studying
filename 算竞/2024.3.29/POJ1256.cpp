#include<iostream>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std; 

bool cmp(char a,char b){
	if(tolower(a)!=tolower(b))return tolower(a)<tolower(b);
	return a<b;
}

char ans[205];

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",ans);
		int m = strlen(ans);
		sort(ans,ans+m,cmp);
		do{
			printf("%s\n",ans);
		}while(next_permutation(ans,ans+m,cmp));
	} 
}
