#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
	set<string> s;
	cin>>n;
	while(n--){
		string t;
		cin>>t;
		s.insert(t);
	}
	cout<<s.size()<<endl;
	return 0;
}
