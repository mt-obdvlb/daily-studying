#include<bits/stdc++.h>

using namespace std;

int n,m;

int main(){
	cin>>n>>m;
	m--;
	vector<int> v(n);
	for(int i = 0;i<n;i++)v[i]=i+1;
	int ind = 0;
	while(!v.empty()){
		ind+=m;
		while(ind>=n)ind -= n;
		cout<<v[ind]<<" ";
		n--;
		v.erase(v.begin()+ind);
		//cout<<ind<<" "<<n<<endl;
		//system("pause");
	}
	return 0;
} 
