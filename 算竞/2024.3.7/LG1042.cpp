#include<iostream>

using namespace std;

char str[100010];
int cnt = 0;

void show(int n){
	int a= 0,b=0;
	for(int i = 0;i<cnt;i++){
		if(str[i]=='W')a++;
		if(str[i]=='L')b++;
		if((a>=n||b>=n)&&abs(a-b)>=2){
			cout<<a<<":"<<b<<endl;
			a=b=0;
		}
	}
	cout<<a<<":"<<b<<endl; 
} 

int main(){
	char c;
	int flag = 1;
	while(cin>>c&&c!='E'){
		if(c=='W'||c=='L')str[cnt++]=c;
	} 
	show(11);
	cout<<endl;
	show(21);
	return 0;
}
