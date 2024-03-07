#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n;
string s[105];
int ind[105];

int main(){
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>s[i];
		ind[i]=i;	
	}
	sort(ind,ind+n,[&](int i,int j)->bool{
		if(s[i].size()!=s[j].size())return s[i].size()>s[j].size();
		return s[i]>s[j];
	});
	cout<<ind[0]+1<<endl<<s[ind[0]]<<endl;
	return 0;
}
