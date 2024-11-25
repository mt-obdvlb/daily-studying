#include<bits/stdc++.h>

using namespace std;
const int N = 1e4;
int z[N];


int main(){
	string s;
	cin>>s;
	int l,r,n;
	l = r = -1,n = s.size();
	z[0]=n;
	for(int i = 1;i<n;i++){
		if(r>=i){
			z[i] = min(z[i-l],r-i+1);
		}
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l = i,r = i + z[i] - 1;
	}
	return 0;
}
