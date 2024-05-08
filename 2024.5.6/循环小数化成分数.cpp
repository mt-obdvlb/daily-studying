#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int main(){
	string s;
	while(cin>>s){
		int a=0,b=0,c=0;
		int ans1 = 0,ans2 = 0;
		int p1 = 0,p2 =0;
		int i;
		for(i = 0;s[i]!='.'&&s[i];i++){
			a*=10;
			a+=s[i]-'0';
		}
		for(i++;s[i]!='{'&&s[i];i++){
			b*=10;
			b+=s[i]-'0';
			p1++,p2++;
		}
		c = b;
		for(i++;s[i]!='}'&&s[i];i++){
			c*=10;
			c+=s[i]-'0';
			p1++;
		}
		if(p1==0){
			cout<<s<<endl;			
		}else{
			ans2 =  pow(10,p1)-pow(10,p2);
			ans1 = c-b+a*ans2;
			int g = gcd(ans1,ans2);
			ans1/=g,ans2/=g;
			printf("%d/%d\n",ans1,ans2);
		}
		
	}
	return 0;
}
