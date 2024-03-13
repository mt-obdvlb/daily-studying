#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){
	int n;
	cin>>n;
	string ans="";
	int ind = 0;
	for(int i = 1;i<=n;i++){
		string t;
		cin>>t;
		if(t.size()>ans.size()){
			ans=t;
			ind = i;
		}else if(t.size()==ans.size()){
			for(int j = 0;j<t.size();j++){
				if(t[j]==ans[j])continue;
				if(t[j]-'0'>ans[j]-'0'){
					ans = t;
					ind = i;
				}else{
					break;
				}
			}
		}
	}
	cout<<ind<<endl<<ans<<endl;
	return 0;
}
