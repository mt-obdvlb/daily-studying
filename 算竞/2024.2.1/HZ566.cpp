#include<bits/stdc++.h>
#include<cctype> 
using namespace std;

int n,m;


int main(){
	cin>>n>>m;
	vector<string> v[1005];
	string user[1005];
	unordered_map<string,int> h;
	int k;
	for(int i = 0;i<m;i++){
		string a,b;
		cin>>a>>b;
		if(h.find(a)==h.end()){
			user[k] = a;
			h[a]=k++;	
		}
		v[h[a]].push_back(b);
		getchar();
	}
	for(int i = 0;i<k;i++){
		cout<<user[i]; 
		for(int j = 0;j<v[i].size();j++){
			cout<<" "<<v[i][j];
		}
		cout<<endl;
	}
	return 0;
}
