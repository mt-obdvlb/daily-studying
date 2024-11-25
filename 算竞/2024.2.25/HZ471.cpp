#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class BigInt;
ostream& operator<<(ostream& out,const BigInt &b);

class BigInt:public vector<int>{
public:
	BigInt(const string &a){
		for(int i = a.size()-1;i>=0;i--)push_back(a[i]-'0');
		update();
	}
	BigInt(int n,int x):vector<int>(n,x){
	}
	BigInt operator*(const BigInt &b){
		BigInt ret((int)b.size()+(int)size()-1,0);
		for(int i = 0;i<b.size();i++){
			for(int j = 0;j<size();j++){
				ret[i+j]+=at(j)*b[i];
			}
			ret.update();
		}
		return ret;
	}
	void update(){
		for(int i = 0;i<size();i++){
			if(at(i)<10)continue;
			if(i==size()-1)push_back(0);
			at(i+1)+=at(i)/10;
			at(i)%=10;
		}
		
	}
};

ostream& operator<<(ostream& out,const BigInt &b){
	for(int i = b.size()-1;i>=0;i--)out<<b[i];
	return out;
}

string a,b;

int main(){
	cin>>a>>b;
	BigInt m(a),n(b);
	cout<<(m*n)<<endl;
	return 0;
}
