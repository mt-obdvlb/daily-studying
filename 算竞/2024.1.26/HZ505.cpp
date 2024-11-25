#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;



int main(){
	int  n;
	cin >> n;
	vector<string> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}	
	sort(v.begin(),v.end(),[&](const string &a,const string &b) ->bool{
		return  a + b> b + a;
	});
	for(int i = 0;i<n;i++){
		cout<<v[i];
	}
	return 0;
}
