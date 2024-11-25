#include<bits/stdc++.h>

using namespace std;

int f(int a){
	if(a == 1){
		return 1;
	}
	return f(a-1)*2 + 2;
}


int main(){
	int a;
	cin>>a;
	cout<< f(a) <<endl;
	return 0;
}
