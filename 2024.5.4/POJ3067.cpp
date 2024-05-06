#include<bits/stdc++.h>

using namespace std;

int n,m,k,c[1000005]; 
struct Data{
	int x,y;
	bool operator<(const Data &d)const{
		if(x!=d.x)return x<d.x;
		return y<d.y;
	}
}e[1000005];

int lowbit(int i){
	return i&(-i);
}

void add(int i){
	while(i<=1005){
		c[i]++;
		i+=lowbit(i);
	}
} 

int sum(int i){
	int s = 0;
	while(i>0){
		s+=c[i];
		i-=lowbit(i);
	}
	return s;
}

int main(){
	int T;
	cin>>T;
	for(int Tt = 1;Tt<=T;Tt++){
		int ans = 0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i = 0;i<k;i++){
			scanf("%d%d",&e[i].x,&e[i].y);
		}
		sort(e,e+k);
		for(int i = 0;i<k;i++){
			ans+= i - sum(e[i].y);
			add(e[i].y);
		}
		printf("Test case %d: %d\n",Tt,ans);
	}
	return 0;
}
