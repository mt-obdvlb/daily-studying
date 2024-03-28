#include<iostream>

using namespace std;

int n;

long long s = 0;
int arr[33000];


int main(){
	scanf("%d",&n);
	for(int i =1;i<=n;i++){
		scanf("%d",arr+i);
		int t = 1000000;
		if(i==1)t = arr[i];
		for(int j = 1;j<i;j++){
			t=min(t,abs(arr[i]-arr[j]));
		}
		s+=t;
	}
	cout<<s<<endl;
	return 0;
} 
