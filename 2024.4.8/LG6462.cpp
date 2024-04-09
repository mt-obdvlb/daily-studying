#include<bits/stdc++.h> 
using namespace std;
#define NO {printf("No\n");continue;}
#define YES {printf("Yes\n");continue; }
int main() {
	long long h,x,y,t;//如题目
	cin >> t;
	while(t--) {
		scanf("%lld%lld%lld",&h,&x,&y);
		if(y >= h)YES//1.
		if(x >= h)NO//2.
		if(y == 0)NO
		if(x == 0)YES//4.
		long long ti = h/x + 1;//英雄能攻击的次数
		h = h % x;//剩余血
		if(h == 0)h = x;//如果打没血了，就少打一次
		if((ti) * y >= h)YES//英雄能造成总伤害比剩余血多，就能打死
		else NO
	}
}
