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
	BigInt(int n,int x):vector<int>(n,x){
		
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
	BigInt operator*(BigInt &b){
		int n = size(),m=b.size();
		BigInt ret(n+m,0);
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				ret[i+j]+=at(i)*b[j];
			}
		}
		ret.update();
		return ret;
	}
};

ostream& operator<<(ostream& out,BigInt &b){
	for(int i = b.size()-1;i>=0;i--)out<<b[i];
	return out;
}

int main(){
	string ta,tb;
	cin>>ta>>tb;
	BigInt a(ta),b(tb);
	a=a*b;
	cout<<a<<endl;
	return 0;
}
