#include<iostream>

using namespace std;
int n,t;

int main(){
	cin>>n;
	int ans = 0;
	while(n--){
		scanf("%d",&t);
		ans^=t;
	}
	cout<<ans<<endl;
	return 0;
}
