#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,q;
	vector<int> v[150005];
	while(cin>>n>>q){
		for(int i = 1;i<=n;i++)v[i].clear();
		while(q--){
			int op,u,x;
			scanf("%d%d%d",&op,&u,&x);
			switch(op){
				case 1:
					int val;
					scanf("%d",&val);
					if(x) v[u].push_back(val);
					else v[u].insert(v[u].begin(),val);
					break;
				case 2:
					if(v[u].empty()){
						printf("-1\n");
						break;
					}
					if(x==0){
						printf("%d\n",*v[u].begin());
						v[u].erase(v[u].begin());
					}else{
						printf("%d\n",*v[u].rbegin());
						v[u].erase(--v[u].end());
					}
					break;
				case 3: 
					int w;
					scanf("%d",&w);
					if(w){
						reverse(v[x].begin(),v[x].end());
					}
					for(auto xx:v[x])v[u].push_back(xx);
					v[x].clear();
			}
		}	
	}
	return 0;
}
