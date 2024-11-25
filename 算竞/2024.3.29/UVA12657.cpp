#include<bits/stdc++.h>

using namespace std;

int l[100005],r[100005];

int main(){
	int n,m,op,x,y,flag,head,tail,a,b;
	while(~scanf("%d%d",&n,&m)){
		flag = 1;
		head = 1,tail = n;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		for(int i = 1;i<=n;i++){
			r[i]=i+1,l[i]=i-1;
		}
		l[1]=-1,r[n]=-1;
		while(m--){
			scanf("%d",&op);
			if(flag){
			int p = head;
			while(p!=tail){
				printf("%d ",p);
				p = r[p];
			}
			printf("%d\n",tail);
		}else{
			int p = head;
			while(p!=tail){
				printf("%d ",p);
				p = l[p];
			}
			printf("%d\n",tail);
		}
		system("pause");
			switch(op){
				case 1:
					scanf("%d%d",&x,&y);
					if(flag){
						if(l[y]==x)continue;
						if(head == x){
							head = r[x];
							l[r[x]]=-1;
						}else if(tail ==x){
							tail = l[x];
							r[l[x]]=-1;
						}
						l[x] = l[y];
						r[x] = y;
						r[l[y]]=x;
						l[y]=x;
					}else{
						if(r[y]==x)continue;
						if(head == x){
							head = l[x];
							r[l[x]]=-1;
						}else if(tail ==x){
							tail = r[x];
							l[r[x]]=-1;
						}
						r[x] = r[y];
						l[x] = y;
						l[r[y]]=x;
						r[y]=x;
					}
					break;
				case 2:
					scanf("%d%d",&x,&y);
					if(flag){
						if(r[y]==x)continue;
						if(head == x){
							head = r[x];
							l[r[x]]=-1;
						}else if(tail ==x){
							tail = l[x];
							r[l[x]]=-1;
						}
						r[x] = r[y];
						l[x] = y;
						l[r[y]]=x;
						r[y]=x;
					}else{
						if(l[y]==x)continue;
						if(head == x){
							head = l[x];
							r[l[x]]=-1;
						}else if(tail ==x){
							tail = r[x];
							l[r[x]]=-1;
						}
						l[x] = l[y];
						r[x] = y;
						r[l[y]]=x;
						l[y]=x;
					}	
					break;
				case 3:
					scanf("%d%d",&x,&y);
					a = l[x],b = r[x];
					l[x] = l[y],r[x] = r[y];
					l[y] = a,r[y] = b;
					break;
				case 4:
					flag^=1;		
					swap(head,tail);	
					break;			
			}
		}
		if(flag){
			int p = head;
			while(p!=tail){
				printf("%d ",p);
				p = r[p];
			}
			printf("%d\n",tail);
		}else{
			int p = head;
			while(p!=tail){
				printf("%d ",p);
				p = l[p];
			}
			printf("%d\n",tail);
		} 
	}
	return 0;
}
