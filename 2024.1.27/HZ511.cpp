#include<iostream>


using namespace std;

long long a,b,k,cnt = 0;


int main(){
	cin>>a>>b>>k;
	if(k == 0||k == 1){
		cout<< b-a<<endl;
		return 0;
	}
	while(1){
		if(a*k<=b){
			cnt += 1 + b%k;
			b/=k;
		}else{
			cnt += (b-a);
			break;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
