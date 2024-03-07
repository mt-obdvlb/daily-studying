#include<iostream>
#include<vector>

using namespace std;

class BigInt:public vector<int>{
public:
	BigInt(const string &s){
		for(int i = s.size()-1;i>=0;i--)push_back(s[i]-'0');
		update();
	}	
	void update(){
		for(int i = 0;i<size();i++){
			if(at(i)<10)continue;
			if(i==size()-1)push_back(0);
			at(i+1)+=at(i)/10;
			at(i)%=10; 
		}
	}
	BigInt operator+(const BigInt &b){
		BigInt ret(*this);
		ret+=b;
		return ret;
	}
	void operator+=(const BigInt &b){
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

int main(){
	string a,b;
	cin>>a>>b;
	BigInt m(a),n(b);
	cout<<(m+n)<<endl;
	
	return 0;
}
