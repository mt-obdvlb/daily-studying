#include<iostream>
#include<set>
using namespace std;

int main(){
	set<int> s;
	ios::sync_with_stdio(false);
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		while(n--){
			int t;
			scanf("%d",&t);
			s.insert(t); 
		}
		while(m--){
			int t;
			scanf("%d",&t);
			s.insert(t); 
		}
		while(!s.empty()){
			printf("%d ",*s.begin());
			s.erase(s.begin());
		} 
		printf("\n");
	}
	return 0;
}
