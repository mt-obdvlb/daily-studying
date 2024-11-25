#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[10005];

int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++)scanf("%d",a+i);
	nth_element(a,a+(n>>1),a+n);
	printf("%d",a[n/2]);	
	return 0;
}
