#include<iostream>
#include<algorithm>


using namespace std;

struct Car{
	int x,d,ind;	
}c[100005];


int n,t,ans[100005],vis[100005]={0};



int main(){
	scanf("%d%d",&n,&t);
	for(int i = 0;i<n;i++){
		scanf("%d%d",&c[i].x,&c[i].d);
		c[i].ind = i; 
	}
	sort(c,c+n,[&](const Car &a,const Car &b)->bool{
		return a.x<b.x;
	});
	for(int l = 1,r=n-1,i = 0;i<t&&l<=r;i++){
		if(vis[0]==0&&c[0].d==-1){
			c[0].x+=t*c[0].d;
			vis[0]=1;
		}else if(vis[0]!=1){
			c[0].x += c[0].d;
		}
		if(vis[n-1]==0&&c[0].d==1){
			c[n-1].x+=t*c[n-1].d;
			vis[n-1]=1;
		}
		while(l<r&&(vis[l]||vis[r])){
			if(vis[l]){
				c[l].x +=t*c[l].d;
				l++;
			}
			if(vis[r]){
				c[r].x +=t*c[r].d;
				r--;
			}
		}
		if(l==r&&vis[l]){
			c[l].d+=t*c[l].d;
		}
		
		for(int i = l;i<r;i++){
			c[i].x+=c[i].d;
			if(vis[i-1]&&c[i-1].d==c[i].d){
				vis[i]=1;
				continue;	
			}
			if(vis[i+1]&&c[i+1].d==c[i].d){
				vis[i]=1;
				continue;	
			}
			if(c[i-1].x>=c[i].x){
				c[i-1].d = -1;
				c[i].d = 1;
			}
			if(c[i-1].x>c[i].x){
				c[i-1].x+=c[i-1].d;
				c[i].x+=c[i].d;
			}
			if(i>=2&&c[i-2].x==c[i-1].x){
				c[i-2].d = -1;
				c[i-1].d = 1;
			}
		}
		if(vis[n-1]==0){
			c[n-1].x+=c[n-1].d;
			if(c[n-1-1].x>=c[n-1].x){
				c[n-1-1].d = -1;
				c[n-1].d = 1;
			}
			if(c[n-1-1].x>c[n-1].x){
				c[n-1-1].x+=c[n-1-1].d;
				c[n-1].x+=c[n-1].d;
			}
			if(n-1>=2&&c[n-1-2].x==c[n-1-1].x){
				c[n-1-2].d = -1;
				c[n-1-1].d = 1;
			}
		}
	}
	for(int i = 0;i<n;i++){
		ans[c[i].ind] = c[i].x;
	}
	for(int i = 0;i<n;i++){
		if(i)printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}
