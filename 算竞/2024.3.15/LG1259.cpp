#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,tn;
char st[255];
void print(){
	for(int i = 0;i<2*(tn+1);i++)printf("%c",st[i]);	
	printf("\n");
}
void print4(){
	for(int i = 9;i<2*(tn+1);i++)printf("%c",st[i]);	
	printf("\n");
}

char dir[4][20]={"ooo*o**--",
				"o--*o**oo",
				"o*o*o*--o",
				"--o*o*o*o"};

int main(){
	cin>>n;
	tn = n;
	memset(st,'-',sizeof(st));
	for(int i = 0;i<n;i++)st[i]='o';
	for(int i = n;i<2*n;i++)st[i]='*';
	print();
	do{
		if(n==4){
			swap(st[n-1],st[2*n]);
			swap(st[n],st[2*n+1]);
			print();
			for(int i = 0;i<4;i++){
			printf("%s",dir[i]);
				print4();
			}
			break;
		}else{
			swap(st[n-1],st[2*n]);
			swap(st[n],st[2*n+1]);
			print();
			swap(st[n-1],st[2*n-1]);
			swap(st[n],st[2*n-2]);
		print();
		}
	}while(n--);

	return 0;
}
