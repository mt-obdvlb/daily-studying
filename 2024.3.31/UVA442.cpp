#include<bits/stdc++.h>

using namespace std;

struct Matrix{
	char name;
	int row,column;
}m[30];

int n,r,c,tot = 0;
char ch;

map<char,int> mp;

int main(){
	cin>>n;
	while(n--){
		cin>>ch>>r>>c;
		m[tot].name=ch;
		m[tot].row=r;
		m[tot].column=c;
		mp[ch]=tot;
		tot++;
	}
	stack<Matrix> st;
	int ans = 0,flag = 0;
	while(~scanf("%c",&ch)){
		if(ch==EOF)return 0;
		if(ch=='\n'){
			if(st.empty())continue;
			if(flag){
				printf("error\n");
			}else{
				printf("%d\n",ans);
			}
			flag = 0;
			ans = 0;
			while(!st.empty())st.pop();
			continue;
		}
		if(flag)continue;
		switch(ch){
			case '(':
				break;
			case ')':{
				
				Matrix sec = st.top();
				st.pop();
				Matrix fir = st.top();
				st.pop();
				if(fir.column!=sec.row)flag=1;
				Matrix newM;
				newM.row=fir.row,newM.column = sec.column;
				ans += fir.row*sec.row*sec.column;
				st.push(newM);
				break;
			}
			default:
				if(!isalpha(ch))break;
				st.push(m[mp[ch]]);
		}
	}
	return 0;
}
