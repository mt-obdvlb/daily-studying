#include<iostream>

using namespace std;


int main(){
	long long c,b,cnt = 0,a[1000] = {0};
	cin>>c>>b;
	if(b == 0||c == 0){
		cout<<(c==0?b:c)<<endl;
		return 0;
	}
	if(b == c){
		cout<<0<<endl;
		return 0; 
	}
	for(long long i = c,j = b;i;i >>= 1,j >>=1 ){
		long long tmp_i = i&1,tmp_j = j&1;
		a[cnt++] = tmp_i^tmp_j;
	}
	long long sum = 0;
	for(long long i = 0;i<cnt;i++){
		sum += (1<<i)*a[i];
	}
	cout<<sum<<endl; 
	return 0;
}
