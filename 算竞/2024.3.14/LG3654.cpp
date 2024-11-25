#include<iostream>
#include<string>
using namespace std;

int r,c,k;
string s[105];

int main(){
	cin>>r>>c>>k;
	for(int i = 1;i<=r;i++){
		cin>>s[i];
	}
	int cnt = 0;
	for(int i = 1;i<=r;i++){
		for(int j = 0;j<c;j++){
			if(s[i][j]=='#')continue;
			int flag = 1;
			for(int p = 0;flag&&p<k;p++){
				if(j+p>=c)flag=0;
				if(s[i][j+p]=='#')flag=0;
			}
			if(flag)cnt++;
			if(k==1)continue;
			flag = 1;
			for(int p = 0;flag&&p<k;p++){
				if(i+p>r)flag=0;
				if(s[i+p][j]=='#')flag=0;
			}
			if(flag)cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
