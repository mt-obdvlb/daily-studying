#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
#include<set>
#include<queue>

using namespace std;

#define MAX_N 100005 


int main(){
	int n,m;
	cin>> n >> m;
	vector< vector<int> > v(n+1);
	queue<int> q;
	int ans[MAX_N] ;
	int arr[MAX_N] = {0};
	for(int a,b,i = 0;i<m;i++) {
		cin>> a >> b;
		arr[b]++;
		v[a].push_back(b);
	}
	for(int i = 1;i<=n;i++){
		if(arr[i] == 0){
			q.push(i);
			ans[i] = 1;
		}
	}
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i = 0,I = v[cur].size();i<I;i++){
			int t = v[cur][i];
			arr[t]--;
			if(arr[t] == 0){
				q.push(t);
			}	
			ans[t] = max(ans[cur] + 1,ans[t]);
		}
	}
	for(int i = 1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
