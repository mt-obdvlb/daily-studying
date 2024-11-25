#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+10;
int P,inv[N];
void get_inv(){
	inv[1]=1;
	for(int i = 2;i<P;i++)inv[i] = ((-P/i)*inv[P%i]%P+P)%P; 
}

int main(){
	
	return 0;
}
