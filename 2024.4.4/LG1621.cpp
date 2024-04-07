#include<bits/stdc++.h>

using namespace std;

int a,b,p;
int fa[100005];
bool vis[100005]={0};

int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}

void merge(int a,int b){
	fa[get(a)]=get(b);
}

int main(){
	cin>>a>>b>>p;
	int ans = b-a+1;
	for(int i = 1;i<=b;i++)fa[i]=i;
	for(int i = 2;i<=b;i++){
		if(vis[i])continue;
		if(i<p){
			for(int j = i*2;j<=b;j+=i){
				vis[j]=1;
			}
		}else{
			for(int j = 2*i;j<=b;j+=i){
				vis[j]=1;
				if(j-i>=a&&get(j)!=get(j-i)){
					merge(j,j-i);
					ans--;
				}
			}
		} 
	}
	cout<<ans<<endl; 
	return 0;
}
