#include<iostream>
#include<string>
using namespace std;

string s;
long long n,num;


int main(){
	cin>>s>>n;
	num=s.size();
	while(num<n){
		long long i = num;
		while(i*2<n)i<<=1;
		n-=i+1;
		if(n==0)n=i;
	}
	cout<<s[n-1]<<endl;
	return 0;
}
