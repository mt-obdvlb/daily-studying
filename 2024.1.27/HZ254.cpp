#include<iostream>
#include<algorithm>

using namespace std;

struct Data{
	int b,e,ind,id;
}arr[50005];

int main(){
	int c;
	cin>>c;
	int a[50005],cnt[50006] = {0};
	
	for(int i = 0;i<c;i++){
		cin>>arr[i].b>>arr[i].e;
		arr[i].id=i;
	}
	sort(arr,arr+c,[&](const Data &a,const Data &b)->bool{
		if(a.b!=b.b)return a.b<b.b;
		return a.id<b.id;
	});
	
	int ans = 0;
	for(int i = 0;i<c;i++){
		int pos = -1;
		for(int j = 0;j<ans;j++){
			if(cnt[j]<arr[i].b){
				pos = j;
				break;
			}
		}
		if(pos==-1){
			pos = (ans++);
		}
		cnt[pos] = arr[i].e;
		a[arr[i].id] = pos+1;
		
	}
	cout<<ans<<endl;
	for(int i = 0;i<c;i++){
		cout<<a[i]<<endl;
	}
	return 0;
} 
