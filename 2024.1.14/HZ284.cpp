#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

class cmp1{
	public:
		bool operator()(PII val1,PII val2){
			if(val1.first!=val2.first){
				return val1.first<val2.first;
			}else{
				return val1.second>val2.second;
			}
		}
};



int main(){
	int n;
	cin>>n;
	set<PII,cmp1> s;
	multiset<int> ret;
	int d = 0;
	for(int i =0;i<n;i++){
		int tmp1,tmp2;
		cin >> tmp1 >> tmp2;
		s.insert(PII(tmp2,tmp1));
	}
	
	//first date
	//second money
	for(int i = 0;i<n;i++){
		PII tmp = *s.begin();
		s.erase(s.begin());
		
		if(tmp.first>ret.size()){
			ret.insert(tmp.second);
		}else{
			if(tmp.second>*ret.begin()){
				ret.erase(ret.begin());
				ret.insert(tmp.second);
			}
		}
		
	}
	
	
	int sum = 0;
	for(auto x : ret){	
		sum +=x;
	}
	cout<<sum;
	return 0;
}
