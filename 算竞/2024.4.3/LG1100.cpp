#include<bits/stdc++.h>

using namespace std;

unsigned int n;

int main(){
	cin>>n;
	unsigned int a = n<<16,b = n>>16;
	cout<<a+b<<endl;
	return 0;
}
