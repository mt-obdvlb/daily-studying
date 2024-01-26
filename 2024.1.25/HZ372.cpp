#include<iostream>
#include<deque>
#include<vector>


using namespace std;


int main(){
	int n,p=-1;
	cin>>n;
	vector<int> A(n),B(n);
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	for(int i = 0;i<n;i++){
		cin>>B[i];
	}
	
	deque<int> dA,dB;
	//dA.push_back(0),dB.push_back(0);
	for(int i = 0;i<n;i++){
		while(!dA.empty()&&A[dA.back()]>=A[i]){
			dA.pop_back();
		}
		dA.push_back(i);
		
		while(!dB.empty()&&B[dB.back()]>=B[i]){
			dB.pop_back();
		}
		dB.push_back(i);
		if(dA.size()!=dB.size()){
			p = i;
			break;
		}
	}
	cout<<p<<endl;
	return 0;
}
