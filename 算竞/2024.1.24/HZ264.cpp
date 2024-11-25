#include<iostream>
#include<vector>
#include<deque>
#include<stack>

using namespace std;


int main(){
	long long n,ans = 1;
	cin>>n;
	vector<long long> v(n+2,-1),l(n+2),r(n+2);
	for(long long i = 1;i<=n;i++){
		scanf("%lld",&v[i]);
	}
	stack<long long> s;
	for(long long i = 1;i<=n+1;i++){
		while(!s.empty()&&v[s.top()]>v[i]){
			r[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()){
		s.pop();
	}
	for(long long i = n;i>=0;i--){
		while(!s.empty()&&v[s.top()]>v[i]){
			l[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	for(long long i = 1;i<=n;i++){
		ans = max(ans,(r[i]-l[i]-1)*v[i]);
	}
	cout<<ans<<endl;
	return 0;
}
