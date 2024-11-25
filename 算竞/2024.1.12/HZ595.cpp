#include<bits/stdc++.h>

using namespace std;

bool _find(vector<string> v,string x){
	for(int i = 0;i<v.size();i++){
		if(v[i]==x){
			return true;
		}
	}
	return false;
}

int main(){
	int n,flag = 0;
	cin>>n;
	vector<string> v(n),ret;
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	string target;
	cin>>target;
	for(int i =0;i<n;i++){
		if(v[i]==target){
			flag = 1;
			ret.push_back(v[i]);
			break;
		}
		if(v[i]=="return"){
			ret.pop_back();
		}else{
			ret.push_back(v[i]);
		}
	}
	if(flag){
		for(int i =0;ret[i]!=target;i++){
			cout<<ret[i]<<"->";
		} 
		cout<<target;
	}else{
		cout<<"NOT REFERENCED"<<endl;
	}
	return 0;
}
