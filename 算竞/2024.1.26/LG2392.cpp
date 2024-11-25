#include<iostream>
#include<vector>

using namespace std;

int s[4];
int ans = 0;
int tmp = 0x3f3f3f3f;

void dfs(vector<int> &v, int k,int l,int r){
	if(k == v.size()){
		tmp = min(tmp,max(l,r));
		return;
	}
	l +=v[k];
	dfs(v,k+1,l,r);
	l -= v[k];
	r +=v[k];
	dfs(v,k+1,l,r);
	r -= v[k];
}

int main(){
	for(int i  =0;i<4;i++){
		cin>>s[i];
	}
	vector<vector<int>> v(4);
	for(int i = 0;i<4;i++){
		v[i].resize(s[i]);
		for(int j = 0;j<s[i];j++){
			cin>>v[i][j];
		}
	}
	for(int i = 0;i<4;i++){
		tmp = 0x3f3f3f3f;
		dfs(v[i],0,0,0);
		ans +=tmp;
	}
	cout<<ans<<endl;
	return 0;
}
