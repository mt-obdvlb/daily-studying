#include<iostream>
#include<set>
using namespace std;

int main(){
	int n;
	cin>>n;
	set<int> s;
	for(int t,i=0;i<n;i++){
		cin>>t;
		s.insert(t);
	}
	int j = 0;
	for(auto x:s){
		j++;
	}
	int flag = 0;
	cout<<j<<endl;
	for(auto x:s){
		if(flag)cout<<" ";
		cout<<x;
		flag=1;
	}
}
