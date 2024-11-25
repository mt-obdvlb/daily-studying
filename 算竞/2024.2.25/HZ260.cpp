#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

class BigInt:public vector<int>{
public:
	BigInt(){
		push_back(0);
	}
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
		while(!empty()&&at(size()-1)==0)pop_back();
	}
	BigInt& operator*(int x){
		for(int i = 0;i<size();i++)at(i)*=x;
		update();
		return *this; 
	}
	void operator/=(int x){
		int y = 0; 
		for(int i = size()-1;i>=0;i--){
			y=y*10+at(i);
			at(i)=y/x;
			y%=x;
		}
		update();
	}
	void operator*=(int x){
		for(int i = 0;i<size();i++)at(i)*=x;
		update();
	}
	
	void operator+=(BigInt &t){
		for(int i = 0;i<t.size();i++){
			if(i>=size())push_back(0);
			at(i)+=t[i];
		}
		update();
	}
	int operator%(int x){
		BigInt ret(*this);
		int y = 0; 
		for(int i = size()-1;i>=0;i--){
			y=y*10+at(i);
			ret[i]=y/x;
			y%=x;
		}
		return y;
	}
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

int main(){
	int g1[256]={0};
	char g2[62]={0};
	for(int i = '0';i<='9';i++){
		g1[i]=i-'0';
		g2[i-'0']=i;	
	}
	for(int i = 'A';i<='Z';i++){
		g1[i]=i-'A'+10;
		g2[i-'A'+10]=i;
	}
	for(int i = 'a';i<='z';i++){
		g1[i]=i-'a'+10+26;
		g2[i-'a'+10+26]=i;
	}
	long long pre,next,a=0;
	BigInt tmp;
	string s;
	string ans;
	cin>>pre>>next>>s;
	cout<<pre<<" "<<s<<endl<<next<<" ";
	for(int i = 0,I = s.size(),j=I-1;i<I;j--,i++){
		BigInt t=1;
		for(int j=1;j<=i;j++)t*=pre;
		tmp += t*g1[s[j]];
	}
	for(int i = 0;!tmp.empty();i++,tmp/=next){
		ans+= g2[tmp%next];
	}
	for(int i = ans.size()-1;i>=0;i--)cout<<ans[i]; 
	cout<<endl; 
	return 0;
}
