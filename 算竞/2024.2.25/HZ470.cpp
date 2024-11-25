#include<iostream>
#include<string>
#include<algorithm>
#include<cinttypes>

using namespace std;

int main(){
	int g[256]={0};
	for(int i = '0';i<='9';i++)g[i]=i-'0';
	for(int i = 'A';i<='Z';i++)g[i]=i-'A'+10;
	int arr[500005]={0};
	int cnt = 0;
	string s;
	while(cin>>s){ 
		for(int i = 0;i<5;i++)arr[cnt]=arr[cnt]*36+g[s[i]];
		cnt++;
	}
	sort(arr,arr+cnt);
	int ans = INT32_MAX;
	for(int i = 1;i<cnt;i++)ans = min(ans,arr[i]-arr[i-1]);
	cout<<ans<<endl;
	return 0;
} 
