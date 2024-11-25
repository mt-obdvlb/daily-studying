#include<bits/stdc++.h>

using namespace std;

int e,m,n,d[50005];

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
	cin>>e>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>d[i];
	}
	d[n+1] = e;
	sort(d,d+n+2);
	int l = 0,r = e,mid;
	while(l<r){
		mid = (l+r+1)/2;
		if(check(mid)){
			l = mid;
		}else{
			r = mid-1;
		}
	}
	cout<<l<<endl;
	return 0;
}
