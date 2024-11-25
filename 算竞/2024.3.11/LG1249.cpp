#include<iostream>
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
	}
	void operator*=(int x){
		for(int i = 0;i<size();i++)at(i)*=x;
		update();
	} 
};
ostream& operator<<(ostream& out,BigInt &b){
	for(int i = b.size()-1;i>=0;i--)out<<b[i];
	return out;
}

int n,cnt=0;
int dp[10005][1000];
int arr[10005];


int main(){
	cin>>n;
	if(n<5){
		cout<<n<<endl<<n;
		return 0;
	}
	int tmp = 0;
	for(int i = 2;i<=n;i++){
		tmp+=i;
		arr[cnt++]=i;
		if(tmp>=n)break;
	}
	BigInt ans(1);
	if(tmp==n){
		for(int i = 0;i<cnt;i++){
			if(i)cout<<" ";
			cout<<arr[i];
			ans*=arr[i];
		}
	}else{
		int k = tmp-n;
		if(k==1||k==2){
			if(k==1)arr[cnt-1]++;
			for(int i = 1;i<cnt;i++){
				if(i!=1)cout<<" ";
				cout<<arr[i];
				ans*=arr[i];
			}
		}else{
			for(int i = 0;i<cnt;i++){
				if(arr[i]==k)continue;
				if(i)cout<<" ";
				cout<<arr[i];
				ans*=arr[i];
			}
		}
	}
	cout<<endl<<ans<<endl;
	return 0;
}
