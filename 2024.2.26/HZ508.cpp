#include<iostream>
#include<set>
using namespace std;

int n;
int ans=0;

int main(){
	cin>>n;
	multiset<int> arr;
	for(int i = 0,t;i<n;i++){
		cin>>t;
		arr.insert(t);
	}
	multiset<int> s;
	int flag = 1;
	while(arr.size()>0){
		if(flag){
			s.insert(*arr.begin());
			arr.erase(arr.begin());
			ans += *arr.begin();
			s.insert(*arr.begin());
			arr.erase(arr.begin());
		}else{
			ans += *arr.rbegin();
			s.insert(*arr.rbegin());
			arr.erase(--arr.end());
			s.insert(*arr.rbegin());
			arr.erase(--arr.end());
		}
		if(arr.size()>0){
			ans+=*s.begin();
			arr.insert(*s.begin());
			s.erase(s.begin());
		}
		flag=(flag+1)%2;
		for(auto x:arr)cout<<x<<" ";
		cout<<endl<<ans<<endl;
		for(auto x:s)cout<<x<<" ";
		cout<<endl; 
	}
	cout<<ans<<endl;
	return 0;
}
