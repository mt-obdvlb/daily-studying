#include<iostream>
#include<algorithm>
using namespace std;

int n,s,a,b;
struct Data{
	int x,y;
}d[5005];

int main(){
	cin>>n>>s>>a>>b;
	for(int i = 0;i<n;i++){
		cin>>d[i].x>>d[i].y;	
	}
	sort(d,d+n,[&](const  Data &c,const Data &e)->bool{
		if(c.x>a+b||e.x>a+b)return c.x<e.x;
		if(c.y!=e.y)return c.y<e.y;	
		return c.x<e.x;
	});
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(a+b<d[i].x)continue;
		if(s<d[i].y)break;	
		s-=d[i].y;
		cnt++;
		
	}
	cout<<cnt<<endl;
	return 0;
}
