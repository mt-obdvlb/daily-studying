#include<bits/stdc++.h>

using namespace std;

int t,op,x;
string name;

int main(){
	scanf("%d",&t);
	unordered_map<string,int> mp;
	while(t--){
		scanf("%d",&op);
		switch(op){
			case 1:
				cin>>name;
				scanf("%d",&x);
				mp[name]=x;
				printf("OK\n");
				break;
			case 2:
				cin>>name;
				if(mp.find(name)==mp.end())printf("Not found\n");
				else printf("%d\n",mp[name]);	
				break;
			case 3:
				cin>>name;
				if(mp.find(name)==mp.end())printf("Not found\n");
				else mp.erase(name),printf("Deleted successfully\n");
				break;
			case 4: 
				printf("%d\n",mp.size());
				break;
		}
	}
	return 0;
}
