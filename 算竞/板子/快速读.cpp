#include<bits/stdc++.h>

using namespace std;

void read(int &x){
	char ch = getchar();
	int flag = 1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')flag=-1; 
		ch = getchar();
	}
	while(ch>='0'&&ch<=9)x = x*10 + ch-'0';
	x*=flag;
}

int main(){
	
	
	return 0;
}
