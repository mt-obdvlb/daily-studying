#include<iostream>
#include<cmath>
using namespace std;

int arr[12];

int b,a;

void is_prime(int cnt){
	int x=0;
	for(int i = 0;i<cnt;i++){
		x*=10;
		x+=arr[i];
	}
	if(x>b||x<a)return;
	if(x%6!=1&&x%6!=5)return;
	if(x&1==0)return;
	for(int i = 3;i*i<=x;i+=2){
		if(x%i==0)return;
	}
	printf("%d\n",x);
}

void dfs(int ind,int cnt){
	if(ind==cnt/2){
		for(int i = 0,j=cnt-1;i<cnt/2;i++,j--){
			arr[j]=arr[i];
		}
		if(cnt&1){
			for(int i = 0;i<10;i++){
				arr[ind]=i;
				is_prime(cnt);
			}
		}else is_prime(cnt);
		return;	
	}
	for(int i = 0;i<10;i++){
		arr[ind]=i;
		dfs(ind+1,cnt);
	}
}

int main(){
	cin>>a>>b;
	int tb = b,ta = a;
	int cntA=0,cntB=0;
	while(a){
		cntA++;
		a/=10;
	}
	int t = b*10;
	while(b){
		cntB++;
		b/=10;
		t/=10;
	}
	a=ta,b=tb;
	if(a==5)cout<<5<<endl;
	if(a<=7&&cntB>1)cout<<7<<endl;
	for(int i = (cntA==1?2:cntA);i<=cntB;i++){
		for(int j = 1;j<10;j+=2){
			arr[0]=j;
			dfs(1,i);
		}
	}
	return 0;
}
