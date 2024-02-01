#include<bits/stdc++.h>
#include<numeric>
using namespace std;


int ans[200005]={0};
int cnt = 0;
multiset<int,greater<int>> ms;


int main(){
	vector<int> s;
	int n;
	cin>>n;
	for(int c,i = 0,M=-1;i<n;i++){
		scanf("%d",&c);
		switch(c){
			case 0:
				int a;
				scanf("%d",&a);
				s.push_back(a);
				ms.insert(a);
				break;
			case 1:
				if(!s.empty()){
					int tmp = s.back();
					s.pop_back();
					ms.erase(ms.find(tmp));
				}
				break;
			case 2:
				if(s.empty())ans[cnt]=0;
				else ans[cnt]=*ms.begin();
				cnt++;
				break;
		}
	}	
	for(int i = 0;i<cnt;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
