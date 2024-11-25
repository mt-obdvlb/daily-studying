#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class BigInt:public vector<int>{
public:
	BigInt(int x){
		push_back(x);
		update();
	}
	BigInt(){
		push_back(0);
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
		for(int i = 0 ;i<size();i++)at(i)*=x;
		update(); 
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
	BigInt operator/(int x){
		BigInt ret(*this);
		ret/=x;
		return ret;
	}
	bool operator<(BigInt &b){
		if(b.size()!=size())return size()<b.size();
		for(int i = size()-1;i>=0;i--){
			if(b[i]==at(i))continue;
			return at(i)<b[i];
		}
		return false;
	}
};

ostream& operator<<(ostream &out,const BigInt &b){
	for(int i = b.size()-1;i>=0;i--)out<<b[i];
	return out;
}

int l[1005],r[1005];
int ind[1005];
BigInt ans[1005];

int main(){
	int n;
	cin>>n;
	for(int i = 0 ;i<=n;i++){
		cin>>l[i]>>r[i];
		ind[i]=i;
	}
	sort(ind+1,ind+n+1,[&](int i,int j)->bool{
		return l[i]*r[i]<l[j]*r[j];
	});
	BigInt sum(l[ind[0]]);
	for(int i = 1;i<=n;i++){
		ans[i]=sum/r[ind[i]];
		//if(ans<sum/r[ind[i]])ans=sum/r[ind[i]];
		sum*=l[ind[i]];
	}
	BigInt ret;
	for(int i = 1;i<=n;i++)if(ret<ans[i])ret=ans[i];
	//for(int i = 1;i<=n;i++)cout<<ans[i]<<endl;
	//if(n!=1)cout<<(sum/l[ind[n]]/r[ind[n]])<<endl;
	 cout<<ret<<endl;
	return 0;
}
