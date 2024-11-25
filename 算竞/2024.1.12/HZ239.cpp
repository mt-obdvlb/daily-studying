#include<bits/stdc++.h>

#define S(x) ((x) * (x))

using namespace std;


typedef long long ll;

void f(long long level,long long id,long long &x,long long &y){
	if(level == 1){
		if(id == 1){
			x = 0,y = 0;
		}else if(id == 2){
			x = 0,y = 1;
		}else if(id == 3){
			x = 1,y = 1;
		}else{
			x = 1,y = 0;
		}
		return;
	}
	long long len = 1LL << (level - 1);
	long long block = len * len;
	long long xx,yy;
	if(id<=block){
		f(level-1,id,xx,yy);
		x = yy,y = xx;
	}else if(id<= block* 2){
		f(level-1,id-block,xx,yy);
		x = xx , y = yy+ len;
	}else if(id<= block * 3){
		f(level-1,id-2*block,xx,yy);
		x = xx + len, y = yy+len;
	}else{
		f(level -1 ,id - 3*block,xx,yy);
		x = 2*len - yy - 1, y =  len - xx - 1;
	}
}



int main(){
	long long t,n,s,d;
	cin>>t;
	while(t--){
		scanf("%lld%lld%lld",&n,&s,&d);
		long long x1,x2,y1,y2;
		f(n,s,x1,y1);
		f(n,d,x2,y2);
		printf("%.0lf\n",10*sqrt(S(x1 - x2)+S(y1 - y2)));
	}
	return 0;
}
