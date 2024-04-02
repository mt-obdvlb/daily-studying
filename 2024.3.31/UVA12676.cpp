#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,t;
	while(cin>>n){
		priority_queue<int,vector<int>,greater<int>> q;
		int ans = n;
		while(n--){
			cin>>t;
			q.push(t);
		}
		while(q.size()>4){
			int t,t1,t2;
			t1 = q.top(),q.pop();
			t2 = q.top(),q.pop();
			t = t1+t2;
			ans+=t;
			q.push(t);
		}
		cout<<ans<<endl;
	}
	return 0;
}
