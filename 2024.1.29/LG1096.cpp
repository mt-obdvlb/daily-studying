#include<iostream>
#include<vector> 

using namespace std;


class BigInt:public vector<int>{
public:	
	BigInt(int x){
		push_back(x);
		process_digit();
	}
	BigInt(){
		push_back(0);
	}
	void process_digit(){
		for(int i = 0;i<size();i++){
			if(at(i)<10)continue;
			if(i== size()-1)push_back(0);
			at(i+1) += at(i)/10;
			at(i)%=10;
		}
	}
	BigInt& operator+(int x){
		at(0)+=x;
		process_digit();
		return *this;
	}
	BigInt& operator*(int x){
		for(int i = 0;i<size();i++)at(i)*=x;
		process_digit();
		return *this;
	}
};

ostream& operator<<(ostream& out,BigInt &b){
	for(int i = b.size()-1;i>=0;i--)out<<b[i];
	return out;
}

BigInt f[205];

int main(){
	int n;
	cin>>n;
	f[1] = 2;
	for(int i = 2;i<=n;i++){
		f[i] = f[i-1]*2 + 2;
	}
	cout<<f[n]<<endl;
	return 0;
}
