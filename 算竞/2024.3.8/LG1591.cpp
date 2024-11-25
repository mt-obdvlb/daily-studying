#include<iostream>
#include<vector>
using namespace std;

int t;

class BigInt:public vector<int>{
public:
	BigInt(int x){
		push_back(x);
		update();
	}
	void update(){
		for(int i = 0;i<size();i++){
			if(at(i)<10)continue;
			if(i==size()-1)push_back(0);
			at(i+1)+=at(i)/10;
			at(i)%=10; 
		}
		while(size()>1&&at(size()-1)==0)pop_back();
	}
	void operator*=(int x){
		for(int i =0;i<size();i++)at(i)*=x;
		update();
	}
};

int main(){
	cin>>t;
	while(t--){
		int n,a,ans=0;
		BigInt x(1);
		cin>>n>>a;
		for(int i = 1;i<=n;i++){
			x*=i;
		}
		for(int i = 0;i<x.size();i++){
			if(x[i]==a)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
