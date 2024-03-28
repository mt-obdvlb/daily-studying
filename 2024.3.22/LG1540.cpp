#include<iostream>
#include<queue>
using namespace std;

int n,m,cnt = 0;

int main(){
	cin>>n>>m;
	deque<int> q;
	while(m--){
		int t;
		cin>>t;
		int flag = 0;
		for(auto x:q){
			if(x==t){
				flag = 1;
				break;
			}
		}
		if(flag)continue;
		cnt++;
		q.push_back(t);
		while(q.size()>n)q.pop_front();
	}
	cout<<cnt<<endl;
	return 0;
}
