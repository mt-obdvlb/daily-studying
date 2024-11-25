#include<iostream>
#include<algorithm> 
using namespace std;

int ind[305],t[305],c[305];

int main(){
	int n;
	cin>>n;
	for(int i =0,m,e ;i<n;i++){
		ind[i]=i;
		cin>>c[i]>>m>>e;
		t[i]=c[i]+m+e;
	}
	sort(ind,ind+n,[&](int i,int j)->bool{
		if(t[i]!=t[j])return t[i]>t[j];
		if(c[i]!=c[j])return c[i]>c[j];
		return i<j;
	});
	for(int i = 0;i<5;i++){
		cout<<1+ind[i]<<" "<<t[ind[i]]<<endl;
	}
	return 0;
}
