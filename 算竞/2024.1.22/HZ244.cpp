#include<iostream>
#include<algorithm> 

using namespace std;

#define MAX_N 500

struct Point{
	int x,y;
}arrP[MAX_N+5];

bool cmp(Point &a,Point &b){
	if(a.x!=b.x){
		return a.x<b.x;
	}
	return a.y<b.y;
}

bool checkY(int c,int n,int L,int l,int r,int len){
	int tmp[len];
	for(int i = l;i<=r;i++){
		tmp[i-l] = arrP[i].y;
	}
	sort(tmp,tmp + len);
	for(int i = c-1;i<len;i++){
		if(tmp[i]-tmp[i-c+1]<L){
			return true;
		}
	}
	return false;
}

bool check(int c,int n,int L){
	for(int i = 0,j = 0;i<n;i++){
		while(arrP[i].x-arrP[j].x>=L){
			j++;
		} 
		if(i-j+1<c){
			continue;
		}
		if(checkY(c,n,L,j,i,i-j+1)){
			return true;
		}
	}
	return false;
}

int solve(int l,int r,int c,int n){
	int head = l,tail = r,L;
	while(head<tail){
		L = (head + tail)/2;
		if(check(c,n,L)){
			tail = L;
		}else{
			head = L + 1;
		}
	}
	return head;
}


int main(){
	int c,n;
	cin>> c >> n;
	for(int i = 0;i<n;i++){
		cin>> arrP[i].x >> arrP[i].y;
	}
	sort(arrP,arrP + n,cmp);
	cout<< solve(0,10000,c,n);	
	return 0;
}
