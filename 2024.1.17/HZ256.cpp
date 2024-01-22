#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

class BigInt:public vector<int>{	
public:
	BigInt(int x){
		this->push_back(x);
		process_digit();
	}
	
	bool operator>(const BigInt &b){
		if(this->size()!=b.size()){
			return this->size()>b.size();
		}
		int n = b.size();
		for(int i = n-1;i>=0;i--){
			if(this->at(i)!=b[i]){
				return this->at(i) > b[i];
			}
		}
		return false;
	}
	
	

	
	void process_digit(){
		for(int i =0;i<size();i++){
			if(at(i)<10){
				continue;
			}
			if(i == size()-1){
				push_back(0);
			}
			at(i+1)+=at(i)/10;
			at(i) %= 10;
		}
		while(size()>1&&at(size()-1)==0){
			pop_back();
		}
	}
	
	void operator*=(int x){
		for(int i = 0;i<size();i++){
			at(i) *= x;
		}
			process_digit();
	}
	
	BigInt operator/(int x){
		BigInt ret(*this);
		int y =0;
		for(int i = size()-1;i>=0;i--){
		 	y = y*10 + this->at(i);
		 	ret[i] = y / x;
		 	y %= x;
		}
		ret.process_digit();
		return ret;
	}
	
};

ostream &operator<<(ostream &out,const BigInt b) {
		for(int i = b.size()-1;i>=0;i--){
			out<< b[i];
		}
		return out;
	}

#define MAX_NUM 1000

int a[MAX_NUM+10],b[MAX_NUM+10],ind[MAX_NUM+10];




int main(){
	int n;
	cin>>n; 
	for(int i = 0;i<=n;i++){
		cin>>a[i]>>b[i];
		ind[i] = i;
	}
	sort(ind+1,ind+n+1,[&](int i,int j) ->bool{
		return a[i]*b[i] < a[j] * b[j];	
	});
	BigInt ret(a[0]),p = ret;
	for(int i =1;i<=n;i++){
		BigInt tmp = p / b[ind[i]];
		if(tmp>ret){
			ret = tmp;
		}
		p *= a[ind[i]];
	}
	cout<< ret <<endl;
	return 0;
} 
