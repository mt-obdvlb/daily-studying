#include<iostream>
#include<vector>

using namespace std;

class BigInt:public vector<int>{
public:
	BigInt(){push_back(0);
	}
	BigInt(int x){
		push_back(x);
		update();
	}
	BigInt operator+(BigInt &b){
		BigInt ret(*this);
		ret += b;
		return ret;
	}
	BigInt& operator+=(BigInt &b){
		for(int i = 0;i<b.size();i++){
			if(i>=size())push_back(b[i]);
			at(i)+=b[i];
		}
		update();
		return *this;
	}
	void update(){
		for(int i = 0;i<size();i++){
			if(at(i)<10)continue;
			if(i==size()-1)push_back(0);
			at(i+1)+= at(i)/10;
			at(i)%=10;
		}
	}
	
	
};

ostream& operator<<(ostream& out ,BigInt& b){
	for(int i = b.size()-1;i>=0;i--){
		out<<b[i];
	}
	return out;
}

BigInt f[505];

int main(){
	int n;
	cin>>n;
	f[0] =f[1]= 0;
	f[2] = 1,f[3]=1;
	for(int i = 4;i<=n;i++){
		f[i] = f[i-2]+f[i-3];
	}
	cout<<f[n]<<endl;
	return 0;
}
