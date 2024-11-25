#include<iostream>
#include<cctype>
using namespace std;

int p1,p2,p3;

int main(){
	cin>>p1>>p2>>p3;
	string s;
	cin>>s;
	for(int i = 0;i<s.size();i++){
		if(s[i]!='-')cout<<s[i];
		else{
			if(i==0||s[i-1]>=s[i+1]||s[i-1]=='-'||s[i+1]=='-')cout<<"-";
			else if(isalpha(s[i-1])&&isdigit(s[i+1]))cout<<"-";
			else if(isdigit(s[i-1])&&isalpha(s[i+1]))cout<<"-";
			else if(s[i-1]+1==s[i+1])continue;
			else{
				if(p1==3){
					for(char c = s[i-1]+1;c<s[i+1];c++){
						for(int j = 0;j<p2;j++)cout<<"*";
					}
				}else if(p3==1){
					if(isalpha(s[i-1])&&isalpha(s[i+1])){
						if(p1==1){
							for(char c = tolower(s[i-1])+1;c<tolower(s[i+1]);c++){
								for(int j = 0;j<p2;j++)cout<<c;
							}
						}else{
							for(char c = toupper(s[i-1])+1;c<toupper(s[i+1]);c++){
								for(int j = 0;j<p2;j++)cout<<c;
							}
						}
					}else{
						for(char c = s[i-1]+1;c<s[i+1];c++){
							for(int j =  0;j<p2;j++)cout<<c;
						}
					}
				}else if(p3==2){
					if(isalpha(s[i-1])&&isalpha(s[i+1])){
						if(p1==1){
							for(char c = tolower(s[i+1])-1;c>tolower(s[i-1]);c--){
								for(int j = 0;j<p2;j++)cout<<c;
							}
						}else{
							for(char c = toupper(s[i+1])-1;c>toupper(s[i-1]);c--){
								for(int j = 0;j<p2;j++)cout<<c;
							}
						}
					}else{
						for(char c = s[i+1]-1;c>s[i-1];c--){
							for(int j =  0;j<p2;j++)cout<<c;
						}
					}
				}
			}
		}
	}
	
	return 0;
}
