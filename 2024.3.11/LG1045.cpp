#include<iostream>
#include<vector>
#include<cmath>
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
		while(size()>1&&at(size()-1)==0)pop_back();
	}
	void operator<<=(int x){
		for(int i = 0;i<x;i++){
			for(int j = 0;j<size();j++)at(j)*=2;
			update();
		}
	}
	void operator-=(int x){
		at(0)-=x;
		for(int i = 0;i<size();i++){
			if(at(i)>=0)break;
			at(i+1)-=1;
			at(i)+=1;
		}
		
	}
	void operator*=(int x){
		for(int i =0 ;i<size();i++)at(i)*=x;
		update();
	}
	BigInt(int n,int x):vector<int>(n,x){
	} 
	BigInt operator*(const BigInt& b){
		BigInt ret(500,0);
		for(int i = 0;i<size();i++){
			for(int j = 0;j<b.size();j++){
				if(i+j>=500)continue;
				ret[i+j]+=at(i)*b[j];
			}
		}
		ret.update();
		return ret;
	}
	void operator+=(int x){
		at(0)+=x;
		update();
	}
}; 

ostream& operator<<(ostream& out,BigInt &b){
	while(b.size()<500)b.push_back(0);
	for(int i = 50;i<=500;i+=50){
		for(int j = 499-i+50;j>=500-i;j--)out<<b[j];
		out<<endl;	
	}
	return out;
}

int main(){
	int p;
	cin>>p;
	BigInt ans(1);
	BigInt base(2);
	int k = log10(2)*p+1; 
	cout<<k<<endl;
	int cnt = 0;
	while(p>0){
		if(p&1){
			ans=ans*base;
		}
		base=base*base;
		p>>=1;
	}
	ans-=1;
	cout<<ans<<endl;
	return 0; 
}
