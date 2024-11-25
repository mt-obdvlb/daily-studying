#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n;
int y[105],m[105],d[105],ind[105];
string s[105];

int main(){
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>s[i]>>y[i]>>m[i]>>d[i];
		ind[i]=i;
	}
	sort(ind,ind+n,[&](int i,int j)->bool{
		if(y[i]!=y[j])return y[i]<y[j];
		if(m[i]!=m[j])return m[i]<m[j];
		if(d[i]!=d[j])return d[i]<d[j];
		return i>j;
	});
	for(int i = 0;i<n;i++){
		cout<<s[ind[i]]<<endl;
	}
	return 0;
}
