#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n,m;

int main(){
	cin>>n;
	vector<int> v(1);
	v[0]=1;
	for(int k,p,i = 2;i<=n;i++){
		cin>>k>>p;
		int ind;
		for(ind = 0;ind<v.size();ind++){
			if(v[ind]==k)break;
		}
		if(p){
			if(ind==v.size()-1)v.push_back(i);		
			else v.insert(v.begin()+1+ind,i);
		}else{
			v.insert(v.begin()+ind,i);
		}
	}
//	for(auto x:v)cout<<x<<" ";
//	cout<<endl;
	int arr[100005]={0};
	for(int i = 1;i<=n;i++){
		arr[i]=1;
	}
	cin>>m;
	while(m--){
		int ind;
		int k;
		cin>>k;
		arr[k]=0;
		//for(ind = 0;ind<v.size();ind++){
		//	if(v[ind]==k)break;
		//}
		//if(ind>=v.size())continue;
		//v.erase(ind+v.begin());
	}
	for(int i = 0;i<n;i++){
		if(arr[v[i]]==0)continue;
		cout<<v[i]<<" ";
	}
	return 0;
}
