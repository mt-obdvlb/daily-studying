#include<iostream>
#include<algorithm>
using namespace std;

int n;
struct Data{
	int b,e;
}d[1000005];


int main(){
	cin>>n;
	for(int i = 0;i<n;i++){
		scanf("%d%d",&d[i].b,&d[i].e);
	}
	sort(d,d+n,[&](const Data &a,const Data &c)->bool{
		if(a.e!=c.e)return a.e<c.e;
		return a.b<c.b;
	});
	int t = 0;
	long long cnt =0;
	
	for(int i = 0;i<n;i++){
		if(t<=d[i].b){
			cnt++;
			t=d[i].e;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
