#include<bits/stdc++.h>

using namespace std;

int N,x,t;

bool has_seven(int x){
	if(x%7==0)return true;
	while(x){
		if(x%10==7)return true;
		x/=10;
	}
	return false;
}

int main(){
	cin>>N>>x>>t;	
	vector<int> v(N);
	for(int i = 0;i<N;i++)v[i]=i+1;
	x--;
	while(v.size()!=1){
		while(x>=v.size())x-=v.size();
		if(has_seven(t)){
			v.erase(v.begin()+x);
			x--	;
		}
		t++,x++;
	}
	cout<<v[0]<<endl;
	return 0;
}
