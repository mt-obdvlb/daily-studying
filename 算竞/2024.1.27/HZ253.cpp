#include<iostream>
#include<algorithm>

using namespace std;

struct Data{
	int a,b;	
}C[2505],L[2505];

bool cmp(const Data &a,const Data &b){
	if(a.b!=b.b)return a.b<b.b;
	return a.a<b.a;
}

int main(){
	int ans = 0,c,l;
	cin>>c>>l;
	for(int i = 0;i<c;i++){
		cin>>C[i].a>>C[i].b;
	}
	for(int i = 0;i<l;i++){
		cin>>L[i].b>>L[i].a;
	}
	sort(C,C+c,cmp);
	sort(L,L+l,cmp);
	for(int i = 0 ;i<c;i++){
		int flag = 0;
		for(int j = 0;j<l&&!flag;j++){
			if(L[j].a==0)continue;
			if(L[j].b>=C[i].a&&L[j].b<=C[i].b){
				flag= 1;
				L[j].a--;
			} 
		}
		ans +=flag;
	}
	cout<<ans<<endl;
	return 0;
}
