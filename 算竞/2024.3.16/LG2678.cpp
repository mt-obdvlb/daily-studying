#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

typedef long long ll;

ll l,m,n;
ll d[50005];

bool check(int x){
	int tot = 0;
    int i = 0;
    int now = 0;
    while (i < n+1){
        i++;
        if (d[i] - d[now] < x)
            tot++;
        else
            now = i;
    }
    if (tot > m)
        return false;
    else
        return true;
} 

int main(){
	cin>>l>>n>>m;
	d[0]=0,d[n+1]=l;
	for(int i = 1;i<=n;i++){
		cin>>d[i];
	}
	ll left = 0,right = l,mid;
	while(left<right){
		mid = (left+right+1)/2;
		if(check(mid)){
			left = mid;
		}else{
			right = mid-1;
		}
		//cout<<left<<" "<<mid<<" "<<right<<endl;
		//system("pause");
	}
	cout<<left<<endl;
	return 0;
}
