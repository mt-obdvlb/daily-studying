#include<bits/stdc++.h>

using namespace std;

int arr[10];

void print_(int n){
	for(int i = 0;i<=n;i++){
		cout<<arr[i];
		if(i!=n){
			cout<<" ";
		}
	}
	cout<<endl;
}

void f(int index,int min,int max){
	if(min>max){
		return;
	}
	for(int i = min;i<=max;i++){
		arr[index] = i;
		print_(index);
		f(index +1,i+1,max);
	}
}


int main(){
	int n;
	cin>>n;
	f(0,1,n);
	return 0;
}
