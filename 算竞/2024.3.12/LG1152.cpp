#include<iostream>
#include<cmath>
using namespace std;

long long vis[1000000]={0};
long long arr[10005];
long long n;

int main(){
	cin>>n;
	cin>>arr[0];
	long long flag = 1;
	for(long long i = 1;i<n;i++){
		cin>>arr[i];
		if(arr[i-1]<0&&arr[i]>0&&(arr[i-1]<-n||arr[i]>n)){
			flag=0;
			break;
		}else if(arr[i-1]>0&&arr[i]<0&&(arr[i-1]>n||arr[i]<-n)){
			flag=0;
			break;
		}
		vis[abs(arr[i-1]-arr[i])]=1;
	}
	for(long long i = 1;flag&&i<n;i++){
		if(vis[i])continue;
		flag = 0;
	}
	if(flag)cout<<"Jolly"<<endl;
	else cout<<"Not jolly"<<endl;
	return 0; 
}
