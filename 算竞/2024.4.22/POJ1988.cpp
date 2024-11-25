#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

int p,x,y,top[30005],stx,sty,tpx,tpy;

char op;

map<int,PII> mp1;
map<PII,int> mp2;

int main(){
	cin>>p;
	for(int i = 1;i<=30005;i++)mp1[i] = PII(i,0),mp2[PII(i,0)]=i;
	while(p--){
		cin>>op;
		if(op=='M'){
			cin>>x>>y;	
			stx = mp1[x].first,sty = mp1[y].first;
			tpx = top[stx];
			top[stx] = -1;
			for(int i = 0;i<=tpx;i++){
				mp1[mp2[PII(stx,i)]] = PII(sty,++top[sty]);
			}
		}else{
			cin>>x;
			cout<<mp1[x].second<<endl;
		}
	}
	return 0;
}
