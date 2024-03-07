#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;

int main(){
	cin>>n;
	vector<int> v(n);
	for(int i = 0,t;i<n;i++){
		scanf("%d",&v[i]);
	}
	sort(v.begin(),v.end());
	while(v.size()!=1){
		int a = v.back();
		v.pop_back();
		int b = v.back();
		v.pop_back();
		v.push_back(max(a,a*b-a-b+2));
	}
	cout<<v[0]<<endl;
	return 0;
}
