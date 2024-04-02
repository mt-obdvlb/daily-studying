#include<bits/stdc++.h>

using namespace std;

int t,n,a;

int main(){
	cin>>t;
	vector<int> v;
	set<int> s;
	while(t--){
		s.clear();
		v.clear();
		scanf("%d",&n);
		while(n--){
			scanf("%d",&a);
			if(s.insert(a).second)v.push_back(a);
		}
		for(auto x:v)printf("%d ",x);
		printf("\n");
	}
	return 0;
}
