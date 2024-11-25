#include<iostream>
#include<algorithm>
using namespace std;

int w,n,p[30005];

int main(){
	cin>>w>>n;
	for(int i = 0;i<n;i++)scanf("%d",p+i);
	sort(p,p+n);
	int p1 = 0,p2 = n-1;
	int cnt = 0;
	while(p1<p2){
		if(p[p1]+p[p2]<=w){
			p1++;
		}
		p2--;
		cnt++;
	}
	if(p1==p2)cnt++;
	cout<<cnt<<endl;
	return 0;
}
