#include<iostream>
#include<string>
#include<cmath>
#include<stack> 
using namespace std;


string f(int x){
	if(x<=2){
		switch(x){
			case 2:
				return "2";
			case 1:
				return "2(0)";
		}
		return "";
	}
	string s="";
	if((x&(x-1))==0){
		s+="2(";
		s+=f((int)log2(x));
		s+=")";
		return s;	
	}
	stack<int> st;
	while(x){
		st.push(x&(-x));
		x=x&(x-1);
	}
	while(st.size()>1){
		s+=f(st.top());
		st.pop();
		s+="+";
	}
	s+=f(st.top());
	return s;
}

int main(){
	int n;
	cin>>n;
	cout<<f(n)<<endl;
	return 0;
}
