#include<iostream>
#include<string>
#include<algorithm>
#include<numeric>
using namespace std;
#define INF 1000000005
int n;
int ind[150];
long long p[150];
string s[115];
long long l[150];

int main(){
	cin>>n;
	int f1 = 0,f2=0;
	for(int i = 0;i<n;i++){
		string t;
		cin>>s[i]>>t>>p[i]>>l[i];
		if(t=="BangZhu"){
		p[i]=INF;
		f1=1;	
		}
		if(t=="FuBangZhu")p[i]=INF-1;
		ind[i]=i;
	}
	sort(ind,ind+n,[&](int i,int j)->bool{
		if(p[i]==p[j])return i<j;
		return p[i]>p[j];
	});
	sort(ind+1,ind+3,[&](int i,int j)->bool{
		return l[i]>l[j];
	});
	sort(ind+3,ind+5,[&](int i,int j)->bool{
		return l[i]>l[j];
	});
	sort(ind+5,ind+9,[&](int i,int j)->bool{
		return l[i]>l[j];
	});

	sort(ind+9,ind+16,[&](int i,int j)->bool{
		return l[i]>l[j];
	});
	sort(ind+16,ind+41,[&](int i,int j)->bool{
		return l[i]>l[j];
	});
	if(n>41)sort(ind+41,ind+n,[&](int i,int j)->bool{
		return l[i]>l[j];
	});
	cout<<s[ind[0]]<<" "<<"BangZhu"<<" "<<l[ind[0]]<<endl;
	for(int i = 1;i<=2&&i<n;i++){
		cout<<s[ind[i]]<<" "<<"FuBangZhu"<<" "<<l[ind[i]]<<endl;
	}
	for(int i = 3;i<=4&&i<n;i++){
		cout<<s[ind[i]]<<" "<<"HuFa"<<" "<<l[ind[i]]<<endl;
	}
	for(int i = 5;i<=8&&i<n;i++){
		cout<<s[ind[i]]<<" "<<"ZhangLao"<<" "<<l[ind[i]]<<endl;
		
	}
	for(int i = 9;i<=9+6&&i<n;i++){
		cout<<s[ind[i]]<<" "<<"TangZhu"<<" "<<l[ind[i]]<<endl;
		
	}
	for(int i = 16;i<=16+24&&i<n;i++){
		cout<<s[ind[i]]<<" "<<"JingYing"<<" "<<l[ind[i]]<<endl;
		
	}
	for(int i = 41;i<n;i++){
		cout<<s[ind[i]]<<" "<<"BangZhong"<<" "<<l[ind[i]]<<endl;
		
	}
	return 0;
}
