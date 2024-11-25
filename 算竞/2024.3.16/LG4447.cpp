#include<iostream>
#include<map>
using namespace std;

typedef map<int,int>::iterator it;

map<int,int> m;

int n;
long long a[100005];

int main(){
	cin>>n;
	for(int i = 0 ;i<n;i++){
		int t;
		cin>>t;
		++m[t];
	}
	int ans = 0x3f3f3f3f;
	while(!m.empty()){
		it  i = m.begin(),j=m.begin();
		i->second--;
		int t = 1;
		for(j++;j!=m.end()&&i->first+1==j->first&&j->second>i->second;i++,j++){
			t++;
			j->second--;
		}
		i = m.begin();
		while(i!=m.end()&&i->second==0){
			m.erase((*i++).first);
		}
		ans=min(ans,t); 
	}
	cout<<ans<<endl;
	
	return 0;
}
