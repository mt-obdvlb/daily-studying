#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int w,n;
vector<int> a;

int main(){
	cin>>w>>n;
	a.resize(n);
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int i =0,j=n-1,cnt = 0;
	while(i<j){
		if(a[i]+a[j]<=w){
			i++,j--;
		}else{
			j--;
		} 
		cnt++; 
	}
	if(i == j)cnt++;
	cout<<cnt<<endl;
	return 0;
}
