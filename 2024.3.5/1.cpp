#include<bits/stdc++.h>

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
	}
	
	void operator+=(BigInt b){
		for(int i = 0;i<b.size();i++){
			if(i>=size())push_back(0);
			at(i)+=b[i];	
		}
		update();
	}
	void operator+=(int x){
		at(0)+=x;
		update();
	}
	void operator-=(int x){
		at(0)-=x;
		for(int i = 0;i<size();i++){
			if(at(i)>=0)continue;
			while(at(i)<0){
				at(i+1)-=1;
				at(i)+=10;
			}
		}
		update();
	}
	BigInt operator-(BigInt &x){
		BigInt ret(*this);
		ret-=x;
		return ret;
	}
	void operator-=(BigInt &x){
		for(int i = 0;i<x.size();i++){
			at(i)-=x[i];
			if(at(i)>=0)continue;
			at(i)+=10;
			at(i+1)-=1;
		}
		update();
	}
	bool operator>(BigInt &b){
		if(size()!=b.size())return size()>b.size();
		for(int i = size()-1;i>=0;i--){
			if(at(i)==b[i])continue;
			return at(i)>b[i];
		}	
	}
	BigInt operator-(int x){
		BigInt ret(*this);
		ret-=x;
		return ret;
	}
};

ostream& operator<<(ostream& out,BigInt &b){
	for(int i = b.size()-1;i>=0;i--)out<<b[i];
	return out;
}

int n,k;
int a[100005],b[100005],c[100055];



BigInt is_green(BigInt t,int i){
	BigInt m = a[i];
	m+=b[i];
	BigInt rm=m;
	while(rm<t)rm+=m;
	if(rm-b[i]>t){
		return 0;
	}
	return rm-t;
} 

int main(){
	cin>>n;
	BigInt t = 1;
	for(int ta,tb,i =0;i<n;i++){
		scanf("%d%d",a+i,b+i);
	}
	for(int i = 0;i<=n;i++)scanf("%d",c+i);
	for(int i = 0;i<n;i++){
		t+=c[i];
		t+=is_green(t,i);
	}
	t+=c[n];
	cout<<t<<endl;
	return 0;
} 
