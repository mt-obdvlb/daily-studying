#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int k[5005],s[5005];
int ind[5005];

int main(){
	cin>>n>>m;
	int p = m*150/100;
	for(int i = 1;i<=n;i++){
		cin>>k[i]>>s[i];		
		ind[i]=i;
	} 
	sort(ind+1,ind+n+1,[&](int i,int j)->bool{
		if(s[i]!=s[j])return s[i]>s[j];
		return k[i]<k[j];
	});
	int num;
	for(num = p;num<=n;num++){
		if(s[ind[p]]!=s[ind[num]])break;
	}
	num-=1;
	cout<<s[ind[p]]<<" "<<num<<endl;
	for(int i = 1;i<=num;i++){
		cout<<k[ind[i]]<<" "<<s[ind[i]]<<endl;
	}
	return 0;
}
