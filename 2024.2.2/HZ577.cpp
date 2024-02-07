#include<bits/stdc++.h>

using namespace std;

int cnt[10000]={0};

int main(){
	string s;
	int ans = 0;
	string sans;
	unordered_map<string,int> h;
	int k = 0;
	while(cin>>s){
		for(int i = 0;i<s.size();i++){
			if(isupper(s[i]))s[i]=tolower(s[i]);
		}
		if(h.find(s)==h.end())h[s]=k++;
		cnt[h[s]]++;
		if(cnt[h[s]]>=ans){
			if(cnt[h[s]]>ans){
				ans = cnt[h[s]];
				sans = s;
			}else{
				if(s<sans)sans = s;
			}
		}
	}
	sort(cnt,cnt+k,[&](int a,int b)->bool{
		return a>b;
	});
	cout<<sans<<" "<<ans<<endl;
	return 0;
}
