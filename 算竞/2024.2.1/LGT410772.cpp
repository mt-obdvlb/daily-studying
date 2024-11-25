#include<bits/stdc++.h>

using namespace std;

int T,M;

class BigInt:public vector<int>{
	BigInt(string &s){
		for(int i = s.size()-1,j = 0;j<s.size();j++,i--)push_back(s[i]);
		process_digit();
	}
	BigInt(){
		push_back(0);
	}
	void process_digit(){
		for(int i = 0;i<size();i++){
			if(at(i)<10)continue;
			if(i==size()-1)push_back(0);
			at(i+1)+=at(i)/10;
			at(i)%=10;
		}
	}
	
};

ostream& operator<<(ostream& out,BigInt &b){
	for(int i = b.size()-1;i>=0;i--)out<<b[i];
	return out;
}


int main(){
	scanf("%d%d",&T,&M);
	while(T--){
		string tA,tB;
		cin>>tA>>tB;
		BigInt A(tA),B(tB);
		BigInt x=B,y=B;
		while(1){
										
			
		}
		cout<<abs(y-x)<<endl;
	}
	return 0;
}
