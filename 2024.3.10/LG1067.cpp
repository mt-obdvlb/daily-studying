#include<iostream>

using namespace std;

int arr[105];

int main(){
	int n;
	cin>>n;
	int flag =1; 
	for(int i  =n;i>=0;i--){
		cin>>arr[i];
		if(arr[i]!=0)flag=0; 
	}
	for(int i  = n;i>0;i--){
		if(arr[i]==0)continue;
		if(arr[i]>0&&i!=n)cout<<"+";
		if(arr[i]==1)printf("x");
		else if(arr[i]==-1)printf("-x");
		else printf("%dx",arr[i]);
		if(i!=1)cout<<"^"<<i;
	}
	if(arr[0]!=0){
		if(arr[0]>0&&n!=0)cout<<"+";
		cout<<arr[0]<<endl;
	} 
	if(flag)cout<<0<<endl;
	return 0;
}
