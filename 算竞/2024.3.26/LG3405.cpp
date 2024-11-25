#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
	cin>>n;
	map<int,int> h[10005];
	int ans =0;
	for(int i = 1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		int A= a[0]*26+a[1];
		int B = b[0]*26+b[1];
		ans+=h[B][A];
		if(A==B)ans-=h[A][B];
		h[A][B]++;
	}
	cout<<ans<<endl;
	return 0;
}
