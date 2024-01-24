#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<numeric>
#include<stack>

using namespace std;


int main(){
	int n,m;
	cin>> n >> m;
	vector<int> v(n);
	vector<int> ps(n);
	for(int i = 0;i<n;i++){
		cin >> v[i];
	}
	partial_sum(v.begin(),v.end(),ps.begin());
	deque<int> d;
	int ans = ps[0];
	d.push_back(0);
	for(int i = 0;i<n;i++){
		ans = max(ans,ps[i]-ps[d.front()]);
		while(!d.empty()&&ps[d.back()]>ps[i]){
			d.pop_back();
		}
		d.push_back(i);
		if(i!=n-1&&i - d.front()==m){
			d.pop_front();
		}
	}
	cout<< ans<<endl;
	return 0;
}
