#include<iostream>
#include<vector>

using namespace std;

int n;

class BigInt:public vector<int>{
public:
	BigInt(int x){
		push_back(x);
		update();
	}
	BigInt(){
		push_back(0);
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
	BigInt operator+(BigInt &x){
		BigInt ret(*this);
		ret+=x;
		return ret;
	}
	void operator+=(BigInt &x){
		for(int i = 0;i<x.size();i++){
			if(i>=size())push_back(0);
			at(i)+=x[i];
		}
		update();
	}
};

ostream& operator<<(ostream &out,BigInt &b){
	for(int i = b.size()-1;i>=0;i--)out<<b[i];
	return out;
}


BigInt f[5005];

int main(){
	cin>>n;
	f[0]=0;
	f[1]=1;
	f[2]=2;
	for(int i = 3;i<=n;i++)f[i]=f[i-1]+f[i-2];
	cout<<f[n]<<endl; 
	return 0;
}
