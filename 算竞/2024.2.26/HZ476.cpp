#include<iostream>
#include<vector>
#include<string>
using namespace std;
class BigInt;
ostream& operator<<(ostream& out,const BigInt &b);
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
		while(size()>1&&at(size()-1)==0)pop_back();
	}
	BigInt(int x){
		push_back(x);
		update();
	}
	bool operator==(const BigInt &x){
		if(x.size()!=size())return false;
		for(int i = 0;i<size();i++){
			if(at(i)==x[i])continue;
			return false;	
		}
		return true;
	}
	bool operator<(const BigInt &x){
		if(x.size()!=size())return size()<x.size();
		for(int i = size()-1;i>=0;i--){
			if(at(i)==x[i])continue;
			return at(i)<x[i];	
		}
		return false;
	}
	BigInt operator%( BigInt &x){
		BigInt tmp(*this);
		if(x==tmp)return BigInt(0);
		int cnt = 0;
		while(x<tmp){
			cnt++;
			x*=10;
		}
		x/=10;
		while(cnt){
			while(x<tmp){
				tmp-=x;
			}
			x/=10;
			cnt--;
		}
		return tmp;
	}
	void operator*=(int x){
		for(int i = 0;i<size();i++)at(i)*=10;
		update();
	}
	void operator-=(const BigInt &b){
		for(int i = 0;i<b.size();i++){
			at(i)-=b[i];
			if(at(i)>=0)continue;
			at(i+1)-=1;
			at(i)+=10;
		}
		update();
	}
	void operator/=(int x){
		int y = 0;
		for(int i =size()-1;i>=0;i--){
			y=y*10+at(i);
			at(i)=y/x;
			y%=x;
		}
		update();
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
	cout<<(n%m)<<endl;
	return 0;
}
