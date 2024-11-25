#include<iostream>
#include<vector>
using namespace std;

class BigInt:public vector<int>{
public:
	BigInt(){
		push_back(0);
		update();
	}
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
	BigInt operator+(BigInt &b){
		BigInt ret(*this);
		ret+=b;
		return ret;
	}
	void operator+=(BigInt &b){
		for(int i = 0;i<b.size();i++){
			if(i>=size())push_back(0);
			at(i)+=b[i];
		}
		update();
	}
};

ostream& operator<<(ostream& out,const BigInt &b){
	for(int i = b.size()-1;i>=0;i--)out<<b[i];
	return out;
}

int m,n;
BigInt f[3];


int main(){
	cin>>m>>n;
	f[m%3]=1,f[(m+1)%3]=1,f[(m+2)%3]=2;
	for(int i = m+3;i<=n;i++){
		f[i%3]=f[(i-1)%3]+f[(i-2)%3];
	}
	cout<<f[n%3]<<endl;
	return 0;
}
