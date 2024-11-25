#include<iostream>
#include<string>

using namespace std;

const int maxn = 50005;
int n;
int c[maxn<<1];
string s;

int lowbit(int i){
	return i&(-i);
}

int sum(int i){
	int s = 0;
	for(;i>0;i-=lowbit(i))s+=c[i];
	return s;
}
int query(int l,int r){
	return sum(r)-sum(l-1);
}


void add(int i,int x){
	for(;i<=n;i+=lowbit(i))c[i]+=x;
}

void solve(){
	memset(c,0,sizeof(c));
	scanf("%d",&n);
	int t;
	for(int i = 1;i<=n;i++){
		scanf("%d",&t);
		add(i,t);
	}
	int i,l,r,x;
	while(cin>>s){
		if(s=="End")break;
		else if(s=="Query"){
			scanf("%d%d",&l,&r);	
			printf("%d\n",query(l,r));
		}else if(s=="Add"){
			scanf("%d%d%d",&i,&x);
			add(i,x);
		}else{
			scanf("%d%d%d",&i,&x);
			add(i,-x);
		}
	}
}


int main(){
	int T;
	cin>>T;
	for(int i = 1;i<=T;i++){
		printf("Case %d:\n",i);
		solve();
	}
	return 0;
}
