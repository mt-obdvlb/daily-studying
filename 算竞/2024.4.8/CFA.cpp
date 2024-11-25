#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

class BigInt:public vector<int>{
public:
	
};

inline int read(){
	int flag = 1;
	int ret = 0;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')flag = -1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret = ret * 10 + ch - '0';
		ch  = getchar(); 
	}
	return ret*flag;
}

int t,n,a,b;

int main(){
	t = read();
	while(t--){
		n = read(),a = read(),b = read();
		if(2*a<=b){
			printf("%d\n",n*a);
		}else{
			printf("%d\n",n/2*b+n%2*a);
		}
	}
	return 0;
} 
