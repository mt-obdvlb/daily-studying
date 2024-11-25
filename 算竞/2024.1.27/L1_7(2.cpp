#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>

using namespace std;

struct Car{
	int x,d,ind;	
}c[100005];


int n,t,ans[100005];

void mysort(int l,int r) {
    #define K 1000
    Car *tmp = new Car[n];
    int *cnt = new int[K]();
    for (int i = l; i < r; i++) cnt[c[i].x % K] += 1;
    for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
    for (int i = r - 1; i >= l; i--) tmp[--cnt[c[i].x % K]] = c[i];
    for(int i = l;i<r;i++)c[i] = tmp[i];
    delete[](cnt);
    cnt = new int[K]();
    for (int i = l; i < r; i++) cnt[c[i].x / K] += 1;
    for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
    for (int i = r - 1; i >= l; i--) tmp[--cnt[c[i].x / K]] = c[i];
    for(int i = l;i<r;i++)c[i] = tmp[i];
}

int main(){
	scanf("%d%d",&n,&t);
	for(int i = 0;i<n;i++){
		scanf("%d%d",&c[i].x,&c[i].d);
		c[i].ind = i; 
	}
	mysort(0,n);
	
	for(int i = 0;i<t;i++){
		c[0].x += c[0].d;
		for(int i = 1;i<n;i++){
			c[i].x+=c[i].d;
			if(c[i-1].x>=c[i].x){
				c[i-1].d = -1;
				c[i].d = 1;
			}
			if(c[i-1].x>c[i].x){
				c[i-1].x+=c[i-1].d;
				c[i].x+=c[i].d;
			}
			if(i>=2&&c[i-2].x==c[i-1].x){
				c[i-2].d = -1;
				c[i-1].d = 1;
			}
		}
	}
	for(int i = 0;i<n;i++){
		ans[c[i].ind] = c[i].x;
	}
	for(int i = 0;i<n;i++){
		if(i)printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}
