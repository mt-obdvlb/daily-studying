#include<bits/stdc++.h> 
using namespace std;
#define NO {printf("No\n");continue;}
#define YES {printf("Yes\n");continue; }
int main() {
	long long h,x,y,t;//����Ŀ
	cin >> t;
	while(t--) {
		scanf("%lld%lld%lld",&h,&x,&y);
		if(y >= h)YES//1.
		if(x >= h)NO//2.
		if(y == 0)NO
		if(x == 0)YES//4.
		long long ti = h/x + 1;//Ӣ���ܹ����Ĵ���
		h = h % x;//ʣ��Ѫ
		if(h == 0)h = x;//�����ûѪ�ˣ����ٴ�һ��
		if((ti) * y >= h)YES//Ӣ����������˺���ʣ��Ѫ�࣬���ܴ���
		else NO
	}
}
