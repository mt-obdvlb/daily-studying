#include<bits/stdc++.h>

using namespace std;

int main(){
	priority_queue<int,vector<int>,greater<int> > q;//���������Ų������� 
	while(q.size()>1){
		int t1 = q.top();q.pop();	
		int t2 = q.top();q.pop();	
		q.push(t1+t2);
	}
	return 0;	
}
