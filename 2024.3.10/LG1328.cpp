#include<iostream>

using namespace std;

int n,na,nb;
int cntA=0,cntB=0;
int a[205],b[205];


int main(){
	cin>>n>>na>>nb;
	for(int i = 0;i<na;i++){
		cin>>a[i];
	}
	for(int i = 0;i<nb;i++){
		cin>>b[i];
	}
	for(int i = 0;i<n;i++){
		int xa = a[i%na],xb=b[i%nb];
		switch(xa){
			case 0:
				if(xb==2||xb==3)cntA++;
				else if(xb==0);
				else cntB++;
				break;
			case 1:
				if(xb==0||xb==3)cntA++;
				else if(xb==1);
				else cntB++;
				break;
			case 2:
				if(xb==1||xb==4)cntA++;
				else if(xb==2);
				else cntB++;
				break;
			case 3:
				if(xb==2||xb==4)cntA++;
				else if(xb==3);
				else cntB++;
				break;
			case 4:
				if(xb==0||xb==1)cntA++;
				else if(xb==4);
				else cntB++;
				break;
		}
	}
	cout<<cntA<<" "<<cntB<<endl;
	return 0;
}
