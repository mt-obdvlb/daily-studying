#include<bits/stdc++.h>

using namespace std;

string s;
int n,arr[100005],k;

bool check(int x){
	int cnt = 0;
	int i = 0;
	while(i<=n){
		i++;
		if(arr[i]>x){
			cnt += (arr[i])/x;
			if(arr[i]%x==0)cnt--;
		}
	}
	
	return cnt<=x;
}

int main(){
	while(getline(cin,s)){
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>arr[i];
		}
		sort(arr+1,arr+1+n);
		cin>>k;
		int l = 0,r = arr[n],mid;
		while(l<r){
			mid = (l+r)>>1;
			if(check(mid)){
				r = mid;
			}else{
				l = mid+1;
			}
		}
		cout<<s<<endl;		
		cout<<mid<<endl<<endl;
		getchar();
		getchar();
	}
	return 0;
}
