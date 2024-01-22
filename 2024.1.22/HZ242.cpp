#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX_N 100000

typedef long long ll;

ll a[MAX_N + 5],b[MAX_N + 5];

bool check(int n,int m,int x){
	for(int i  =1;i<=n;i++){
		b[i] = a[i] - x;
	}
	b[0] = 0;
	for(int i = 1;i<=n;i++){
		b[i] += b[i-1];
	}
	ll pre = 0;
	for(int i = m;i<=n;i++){
		pre = min(pre,b[i - m]);
		if(b[i] - pre >= 0){
			return true;
		}
	}
	return false;
}

ll solve(int n,int m,int Max){
	int mid,head = 0,tail = Max;
	while(head<tail){
		mid = (head + tail + 1)/2;
		if(check(n,m,mid)){
			head = mid;
		}else{
			tail = mid - 1;			
		}
	}
	return head;
}

int main(){
	int m,n,max_num = 0;
	cin>>n>>m;
	for(int i = 1,tmp;i<=n;i++){
		scanf("%d",&tmp);
		tmp*=1000;
		a[i] = tmp;
		max_num = max(max_num,tmp);
	}
	cout<< solve(n,m,max_num)<<endl;
	return 0;
}  
