#include<iostream>
#include<vector>
#include<string>

using namespace std;

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
		while(size()>1&at(size()-1)==0)pop_back();
	}
	void operator*=(int x){
		for(int i = 0;i<size();i++)at(i)*=x;
		update();
	}
	void operator+=(BigInt &b){
		for(int i = 0;i<b.size();i++){
			if(i>=size())push_back(0);
			at(i)+=b[i];
		}
		update();
	}
};

ostream& operator<<(ostream &out,const BigInt &b){
	for(int i =b.size()-1;i>=0;i--)out<<b[i];
	return out;
}

int main(){
	int n;
	cin>>n;
	BigInt ans(0);
	for(int i = 1;i<=n;i++){
		BigInt tmp(1);
		for(int j = 1;j<=i;j++){
			tmp*=j;
		}
		ans+=tmp;
	}
	
	cout<<ans<<endl;
	return 0;
} 
