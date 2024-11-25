#include<bits/stdc++.h>

using namespace std;

int c[1050][1050],n;

int lowbit(int i){
	return i&(-i);
}

void add(int x,int y,int v){
	for(int i = x;i<=n;i+=lowbit(i)){
		for(int j = y;j<=n;j+=lowbit(j)){
			c[i][j]+=v;
		}
	}
}

int sum(int x,int y){
	int s = 0;
	for(int i = x;i>0;i-=lowbit(i)){
		for(int j = y;j>0;j-=lowbit(j))s+=c[i][j];
	}
	return s;
}

int main(){
	int op,x,y,v,l,b,r,t;
	while(cin>>op&&op!=3){
		switch(op){
			case 0:
				cin>>n;
				break;
			case 1:
				cin>>x>>y>>v; 
				add(x+1,y+1,v);
				break;
			case 2:
				cin>>l>>b>>r>>t;
				int s1 = sum(r+1,t+1);
				int s2 = sum(r+1,b);
				int s3 = sum(l,t+1);
				int s4 = sum(l,b);
				cout<<s1-s2-s3+s4<<endl;
				break;
		}		
	}	
	return 0;
}
