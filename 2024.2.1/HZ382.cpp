#include<bits/stdc++.h>


using namespace std;

int n,m;



int main(){
	cin>>n>>m;
	vector<int> v(n);
	for(int i = 0;i<n;i++)v[i]=i;
	int tail = 0;
	while(v.size()!=1){
		int ind = tail+m-1;
		while(ind>=v.size())ind-=v.size();
		vector<int>::iterator it = v.begin()+ind;
		v.erase(it);
		tail = ind;
	}
	cout<<v[0]+1<<endl;
	return 0;
}
