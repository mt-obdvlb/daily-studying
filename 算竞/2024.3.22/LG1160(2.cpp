#include<bits/stdc++.h>

using namespace std;

int l[100005],r[100005];
	int vis[100005];

int m,n;

int main(){
	cin>>n;
	fill(l,l+100005,-1);
	fill(r,r+100005,-1);
	fill(vis,vis+100005,1);
	int head = 1;
	for(int k,p,i=2;i<=n;i++){
		cin>>k>>p;
		if(p){
			if(r[k]==-1){
				r[k]=i;
				l[i]=k;
				r[i]=-1;
			}else{
				r[i]=r[k];
				l[r[k]]=i;
				r[k]=i;
				l[i]=k;
				
			}
		}else{
			if(l[k]==-1){
				r[i]=k;
				l[k]=i;
				l[i]=-1;
				head=i;
			}else{
				l[i]=l[k];
				r[l[k]]=i;
				l[k]=i;
				r[i]=k;	
			}
			
		}
	}
	cin>>m;
	while(m--){
		int k;
		cin>>k;
		if(vis[k]==0)continue;
		vis[k]=0;
		if(l[k]==-1){
			l[r[k]]=-1;
			r[0]=r[k];
		}else if(l[k]!=-1&&r[k]!=-1){
			r[l[k]]=r[k];
			l[r[k]]=l[k];
		}else{
			r[l[k]]=-1;
		}
		
	}

	while(head!=-1){
		cout<<head<<" ";
		head = r[head]; 
	}
	return 0;
}
