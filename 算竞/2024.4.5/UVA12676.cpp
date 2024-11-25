#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v[55];
ll n,tmp,maxd,x; 

int main(){
	while(cin>>n){
		tmp = 1;
		maxd = 0;
		for(int i = 0 ;i<n;i++)v[i].clear();
		for(int i  = 0;i<n;i++){
			cin>>x;
			v[x].push_back(0);
			maxd = max(maxd,x);
		}
		for(int i = maxd;i>0;i--){
			for(int j = 0;j<v[i].size();j++){
				if(!v[i][j])v[i][j]=tmp;
			}
			sort(v[i].begin(),v[i].end());
			for(int j = 0;j<v[i].size();j+=2)v[i-1].push_back(v[i][j]+v[i][j+1]);
			tmp = v[i][v[i].size()-1];
		}
		cout<<v[0][0]<<endl;
	}
	
	return 0;
}
