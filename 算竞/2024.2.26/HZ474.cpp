#include<iostream>
#include<string>
#include<vector>

using namespace std;

class BigInt:public vector<int>{
public:
	BigInt(int x){
		push_back(x);
		update();
	}
	void update(){
		for(int i = 0;i<size();i++){
			if(at(i)<10)continue;
			if(i==size()-1)push_back(0);
			at(i+1)+=at(i)/10;
			at(i)%=10;
		}
		while(size()>1&&at(size()-1)==0)pop_back();
	}
	void operator*=(int x){
		for(int i  =0;i<size();i++)at(i)*=x;
		update();
	}
};

ostream& operator<<(ostream& out,const BigInt& b){
	int j;
	for(j = 0;b[j]==0&&j<b.size();j++){
	}
	for(int i = b.size()-1;i>=j;i--)out<<b[i];
	return out;
}

int n;
string s;


int main(){
	cin>>n>>s;
	int g[256]={0};
	for(int i = 'A',j=0;i<='D';i++,j++)g[i]=j;
	int ans[105]={0};
	for(int i = 0;i<n;i++)ans[i]=g[s[i]];
	BigInt Ans=1;
	int cnt=0,flag=0,point = 0;
	for(int i = 0;i<n;i++){
		for(int j  =0;j<4;j++){
			int t;
			cin>>t;
			getchar(); 
			if(j!=ans[i])continue;
			if(t==100)cnt++;
			if(t==0)flag=1;
			Ans*=t;
			point+=2;
		}
	}
	if(cnt==n)cout<<1<<endl;
	else if(flag)cout<<0<<endl;
	else{
		printf("0.");
		for(int i = 1;i<point-Ans.size()+1;i++)cout<<"0";
		cout<<Ans<<endl;
	}
	return 0;
}
