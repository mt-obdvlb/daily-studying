#include<iostream>

using namespace std;

int n;
int cnt = 0;

int dir[3001]= {6,2,5,5,4,5,6,3,7,6};


int main() {
	for(int i = 10;i<=3000;i++){
		int t=i;
		while(t){
			dir[i]+=dir[t%10];
			t/=10;
		}
	}
	cin>>n;
	n-=4;
	for(int i = 0; i<1300; i++) {
		for(int j = 0; j<1300; j++) {
			if(dir[i]+dir[j]+dir[i+j]==n){
			cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
