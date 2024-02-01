#include<bits/stdc++.h>

using namespace std;

int m,n,cnt = 0;
int arr[100000];


int main(){
	cin>>m>>n;
	unordered_map<int,int> h;
	for(int a,i = 0,j=0,k=0;i<n;i++){
		scanf("%d",&a);
		if(h.find(a)!=h.end())continue;
		if(k-j>=m){
			h.erase(h.find(arr[j]));
			j++;
		}
		h[a]=k;
		arr[k++]=a;
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
