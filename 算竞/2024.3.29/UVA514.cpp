#include<iostream>
#include<stack>

using namespace std;

int main(){
	stack<int> s;
	int n,tot,flag;
	while(cin>>n&&n){
		while(1){
			while(!s.empty())s.pop();
			tot = 1,flag = 1;
			for(int i = 0,t;flag&&i<n;i++){
				cin>>t;
				if(t==0){
					flag = 0;
					break;
				}
				while((s.empty()||s.top()<t)&&tot<=n){
					s.push(tot++);
				}
				if(!s.empty()&&s.top()==t)s.pop();
			}
			if(flag==0)break;
			if(s.empty()&&tot==n+1	)printf("YES\n");
			else printf("NO\n");
		}
		printf("\n");
	}
	return 0;
}
