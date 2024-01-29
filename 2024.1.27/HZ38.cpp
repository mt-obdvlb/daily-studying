#include<iostream>
#include<vector>

using namespace std;

class BigInt:public vector<int>{
public:
	BigInt(){
		push_back(0);
	}
	BigInt(int a){
		push_back(a);
		update();
	}
	
	BigInt& operator+=(const BigInt &a){
		for(int i = 0;i<a.size();i++){
			if(i>=size())push_back(a[i]);
			else at(i)+=a[i];	
		}
		update();
		return *this;
	}
	
	BigInt operator+(const BigInt &a){
		BigInt ret(*this);
		ret +=a;
		return ret;
	}
	
	void update(){
		for(int i = 0;i<size();i++){
			if(at(i)<10)continue;
			if(i == size()-1)push_back(0);
			at(i+1) += at(i)/10;
			at(i)%=10;
		}
		while(at(size()-1) == 0){
			pop_back();
		}
	}
	
};
	ostream& operator<<(ostream& out,const BigInt &a){
		for(int i = a.size()-1;i>=0;i--){
			out<<a[i];
		}
		return out;
	}

BigInt arr[105];

int main(){
	int n;
	cin>>n;
	arr[1] = 1;
	arr[2] = 2;
	for(int i = 3 ;i<=n;i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	cout<<arr[n]<<endl;
	return 0;
}
