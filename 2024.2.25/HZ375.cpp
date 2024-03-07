#include<iostream>
#include<algorithm>

using namespace std;

int n;
struct Data{
	int c,t;
}arr[305];
int ind[305];

int main(){
	cin>>n;
	for(int i = 0,m,e;i<n;i++){
		ind[i]=i;
		cin>>arr[i].c>>m>>e;
		arr[i].t=arr[i].c+m+e;
	}
	sort(ind,ind+n,[&](int i,int j)->bool{
		if(arr[i].t!=arr[j].t)return arr[i].t>arr[j].t;
		return arr[i].c>arr[j].c;
	});
	for(int i =0;i<5;i++)cout<<ind[i]+1<<" "<<arr[ind[i]].t<<endl;
	return 0;
}
