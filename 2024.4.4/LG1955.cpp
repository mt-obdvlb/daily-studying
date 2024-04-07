#include<bits/stdc++.h>

using namespace std;

int t,n,ti,tj,tot,i[200005],j[200005],e[200005],ind[200005]; 

int fa[200005];

int get(int x){
	return fa[x]==x?x:fa[x] = get(fa[x]);
}

void merge(int a,int b){
	fa[get(a)] = get(b);
}

int main(){
	cin>>t;
	while(t--){
		scanf("%d",&n);	
		tot = 0;
		unordered_map<int,int> mp;
		for(int k = 1;k<=2*n+5;k++)fa[k]=k,ind[k]=k;
		for(int k = 1;k<=n;k++){
			scanf("%d%d%d",&ti,&tj,e+k);
			if(mp.find(ti)==mp.end())mp[ti]=++tot;
			if(mp.find(tj)==mp.end())mp[tj]=++tot;
			i[k]=mp[ti],j[k]=mp[tj];
		}
		sort(ind+1,ind+1+n,[&](int i,int j)->bool{
			return e[i]>e[j];
		});
		int flag = 1;
		for(int k = 1;k<=n;k++){
			if(e[ind[k]])merge(i[ind[k]],j[ind[k]]);
			else if(get(i[ind[k]])==get(j[ind[k]])){
				printf("NO\n");	
				flag = 0;
				break;	
			}			
		}
		if(flag)printf("YES\n");
	}
	return 0;
}
