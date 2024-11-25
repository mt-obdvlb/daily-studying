#include<iostream>
#include<set>
#include<vector>

using namespace std;

#define MAX_N 2005


int main(){
	int m,n,cnt= 0;
	cin>> m >> n;
	int ans[2005],indure[MAX_N] = {0}; 
	set<int> h;
	vector<vector<int>> v(m+1);
	for(int a,b,i = 0;i<n;i++){
		cin>> a >> b;
		indure[b]++;
		v[a].push_back(b);
	}
	for(int i = 1;i<=m;i++){
		if(indure[i] == 0){
			h.insert(i);
		}
	}
	while(h.size()!=0){
		int tmp = *h.begin();
		h.erase(h.begin());
		ans[cnt++] = tmp;
		for(int i =0,I = v[tmp].size();i<I;i++){
			indure[v[tmp][i]]--;
			if(indure[v[tmp][i]] == 0){
				h.insert(v[tmp][i]);
			}
		}
	}
	for(int i = 0;i<m;i++){
		if(i){
			cout<<" ";
		}
		cout<< ans[i];		
	}
	return 0;
} 
