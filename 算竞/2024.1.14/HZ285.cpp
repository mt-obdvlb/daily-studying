#include<bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

class cmp{
	public:
		bool operator()(int val1,int val2){
			return val1>val2;
		}
};

int main(){
	int n, m;
	multiset<int,cmp> s;
	cin >> n >> m;
	s.insert(0);
	for(int i = 0;i<n;i++){
		vector<int> v;
		for(auto x : s){
			v.push_back(x);
		}
		s.clear();
		for(int j = 0,a;j<m;j++){
			cin>>a;
			for(auto x : v){
				if(s.size()<m||*s.begin()>x+a){
					s.insert(x+a);
				}
				if(s.size()>m){
					s.erase(s.begin());
				}
			}	
		}
		
	}

	int flag =  0;
	for(auto it = s.rbegin();it !=s.rend();it++){
		if(flag){
			cout<<" ";
		}
		cout<<*it;
		flag = 1;
	}
	return 0;
}
