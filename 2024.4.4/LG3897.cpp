#include<bits/stdc++.h>

using namespace std;

int n,l,m;
string t;

int main(){
	cin>>n;
	unordered_map<string,set<int>> mp;
	for(int i =1;i<=n;i++){
		scanf("%d",&l);
		for(int j = 1;j<=l;j++){
			cin>>t;
			mp[t].insert(i);	
		}
	}
	cin>>m;
	while(m--){
		cin>>t;
		set<int> st(mp[t]);
		while(!st.empty()){
			printf("%d ",*st.begin());
			st.erase(st.begin());
		}
		printf("\n");
	}
	return 0;
}
