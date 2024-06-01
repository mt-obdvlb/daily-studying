#include<bits/stdc++.h>

using namespace std;
string s,t;
int n;

int get(const string &s){
	int i = 0,j=1,k=0;
	while(i<n&&j<n&&k<n){
		if(s[(i+k)%n]==s[(j+k)%n])k++;
		else if(s[(i+k)%n]>s[(j+k)%n]){
			i = i+k+1;
			k = 0;
		}else{
			j = j+k+1;
			k = 0;
		}
		if(i==j)j++;
	}
	return min(i,j);
}

int main(){
	cin>>s>>t;
	n = s.size();
	int sm=get(s);
	int tm = get(t);
	int flag = 1;
	for(int i = 0;flag&&i<n;i++) {
		if(s[(i+sm)%n]==t[(i+tm)%n])continue;
		flag=0;
	}
	if(!flag)cout<<"No"<<endl;
	else {
	cout<<"Yes"<<endl;
		for(int i = 0;i<n;i++)printf("%c",s[(i+sm)%n]);
		
		
	}
	return 0;
}
