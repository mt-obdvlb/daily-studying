#include<iostream>
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
	BigInt& operator+=(const BigInt& b){
		for(int i = 0;i<b.size();i++){
			if(i>=size())push_back(b[i]);
			else at(i)+=b[i];
		}
		update();
		return *this;
	}
	
	void update(){
		for(int i = 0;i<size();i++){
			if(at(i)<100000)continue;
			if(i == size()-1)push_back(0);
			at(i+1) += at(i)/100000;
			at(i)%=100000;
		}
		//while(!empty()&&back()==0)pop_back();
	}
	
};

ostream& operator<<(ostream& out,BigInt& b){
	out<<b[b.size()-1];
	for(int i = (int)b.size()-2;i>=0;i--){
		for(int j = 10000;j>0;j/=10){
			out<<b[i] %(j*10)/j;
		}
	}
	return out;
}

int n,k;
BigInt f[2][15][15];

int main(){
	scanf("%d%d",&n,&k);	
	for(int i = 1;i<=k;i++)f[1][i][i]=1;
	for(int ws = 2;ws<=n;ws++){
		for(int i = 1;i<=k;i++){
			for(int j = 1;j<=k;j++){
				f[ws%2][i][j] = 0;
				for(int l = 1;l<=k;l++){
					if(l==j)continue;
					f[ws%2][i][j]+=f[(ws-1)%2][i][l];
				}
			}
		} 
	}
	
	BigInt ans = 0;
	for(int i = 1;i<=k;i++){
		for(int j = 1;j<=k;j++){
			if(i==j)continue;
			ans+=f[n%2][i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
