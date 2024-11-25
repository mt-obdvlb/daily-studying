#include<iostream>
#include<set>
using namespace std;

int main(){
	int n;
	cin>>n;
	multiset<int> s;
	for(int i = 0,t;i<n;i++){
		scanf("%d",&t);
		s.insert(t); 
	}
	long long ans = 0;
	while(s.size()!=1){
		int a = *s.begin();
		s.erase(s.begin());
		int b = *s.begin();
		s.erase(s.begin());
		ans+=a+b;
		s.insert(a+b);
	}
	cout<<ans<<endl;
	return 0;
}
