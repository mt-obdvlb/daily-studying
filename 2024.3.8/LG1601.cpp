#include<iostream>
#include<vector>
#include<string>

using namespace std;

class BigInt:public vector<int>{
public:
	BigInt(string &s){
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
		while(size()>1&&at(size()-1)==0)pop_back();
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

ostream& operator<<(ostream &out,const BigInt &b){
	for(int i = b.size()-1;i>=0;i--)out<<b[i];
	return out;
}

int main(){
	string ta,tb;
	cin>>ta>>tb;
	BigInt a(ta),b(tb);
	cout<<(a+b)<<endl;
	return 0;
}
