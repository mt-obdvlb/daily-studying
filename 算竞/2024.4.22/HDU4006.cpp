#include<bits/stdc++.h>

using namespace std;

int n,k,x;
char op;


int main(){
	while(cin>>n>>k){
		priority_queue<int,vector<int>,greater<int>> q;
		while(n--){
			cin>>op;
			if(op=='Q'){
				cout<<q.top()<<endl;
				q.pop();
			}else{
				cin>>x;
				if(q.size()<k)q.push(x);
				else if(x>q.top()){
					q.pop();
					q.push(x);
				}
			}
		}		
	}
	return 0;
}
