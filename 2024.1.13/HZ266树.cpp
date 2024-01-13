#include<bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

bool is_caluAlpha(string &s,int pos){
	return (pos == 0||(!isdigit(s[pos-1])&&s[pos-1]!=')'))==false;
} 

int calu(string &s,int l,int r){
	int pos = -1,min_pri = INF-1,cur_pri,tmp_pri = 0;
	for(int i = l;i<r;i++){
		cur_pri = INF;
		switch(s[i]){
			case '(':
				tmp_pri+=100;
				break;
			case ')':
				tmp_pri-=100;
				break;
			case '+':
			case '-':
				if(is_caluAlpha(s,i)){
					cur_pri = tmp_pri + 1;
				}
				break;
			case '*':
			case '/':
				cur_pri = tmp_pri + 2;
				break;
			case '^':
				cur_pri = tmp_pri + 3;
				break;
		}
		if(min_pri>=cur_pri){
			pos = i;
			min_pri = cur_pri;
		}
	}
	if(pos == -1){
			int sum=0,flag = 0;
			for(int i = l;i<r;i++){
				if(s[i]=='-'){
					flag = 1;
				}
				if(isdigit(s[i])){
					sum*=10;
					sum += s[i] - '0';
				}
			}
			return sum *(flag==1?-1:1);
	}else{
		int a = calu(s,l,pos);
		int b = calu(s,pos+1,r);
		switch(s[pos]){
			case '+':
				return a + b;
			case '-':
				return a - b;
			case '*':
				return a * b;
			case '/':
				return a / b;
			case '^':
				return (int)pow(a,b);
		}
	}
}


int main(){
	string s;
	cin>>s;
	cout<< calu(s,0,s.size())<<endl;
	return 0;
}
