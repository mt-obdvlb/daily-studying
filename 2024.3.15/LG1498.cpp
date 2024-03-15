#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char a[1024][1024];

int main(){
	int n;
	cin>>n;
	int len = 4,k = 1;
	memset(a,' ',sizeof(a));
	a[0][0]=a[1][1]='/',a[0][1]=a[0][2]='_',a[1][2]=a[0][3]='\\';
	while(n>k){
		for(int i = 0;i<len/2;i++){
			for(int j = 0;j<len;j++){
				a[i+len/2][j+len/2]=a[i][j+len]=a[i][j];
			}
		}
		k++,len<<=1;
	}
	for(int i = len/2-1;i>=0;i--){
		for(int j = 0;j<len;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
