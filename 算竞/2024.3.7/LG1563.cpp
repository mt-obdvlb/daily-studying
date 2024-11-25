#include<iostream>

using namespace std;

int n,m;
int a[100005];
char str[100005][11];

int main(){
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i]>>str[i];
	}
	int ans = 1;
	for(int b,s,i = 0;i<m;i++){
		cin>>b>>s;
		if(b==0){
			if(a[ans-1]==0){
				ans-=s;
			}else{
				ans+=s;
			}
		}else{
			if(a[ans-1]==0){
				ans+=s;
			}else{
				ans-=s;
			}
		}
		if(ans>n)ans-=n;
		if(ans<1)ans=n+ans;
	}
	cout<<str[ans-1]<<endl;
	return 0;
}
