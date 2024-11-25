#include<iostream>
#include<stack>
using namespace std;

int t,q;

int push[1000005];
int pop[1000005];

int main(){
	cin>>t;
	while(t--){
		scanf("%d",&q);
		for(int i=1;i<=q;i++)scanf("%d",push+i);
		for(int i=1;i<=q;i++)scanf("%d",pop+i);
		stack<int> s;
		int cnt = 1;
		for(int i = 1;i<=q;i++){
			while(s.empty()||(cnt<=q&&s.top()!=pop[i])){
			 	s.push(push[cnt++]);
			}
			
			if(s.top()==pop[i])s.pop();
		}
		
		if(s.empty())printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
