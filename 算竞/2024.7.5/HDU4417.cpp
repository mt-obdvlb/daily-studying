#include<iostream>
#include<algorithm>
#define lc t[i].ch[0]
#define Lc t[j].ch[0]
#define rc t[i].ch[1]
#define Rc t[j].ch[1]
#define mid ((l+r)>>1)

using namespace std;
const int N = 1e5+10;
int a[N],b[N],n,m;
int cnt,rt[N];
struct segment_tree{
	int num,ch[2];
}t[N*20];

void update(int &i,int j,int l,int r,int k){
	i = ++cnt;
	t[i] = t[j];
	++t[i].num;
	if(l==r)return;
	if(k<=mid) update(lc,Lc,l,mid,k);
	else update(rc,Rc,mid+1,r,k);
}

int query(int i,int j,int l,int r,int k){
	if(l==r)return t[j].num-t[i].num;
	int ans = 0;
	if(k<=mid) ans+=query(lc,Lc,l,mid,k);
	else{
		ans+=t[Lc].num-t[lc].num;
		ans+=query(rc,Rc,mid+1,r,k); 
	}
	return ans;
}

int main(){
	int T;
	cin>>T;
	for(int tt = 1;tt<=T;tt++){
		printf("Case %d:\n",tt);
		scanf("%d%d",&n,&m);
		for(int i = 1;i<=n;i++){
			scanf("%d",a+i);
			b[i]=a[i];
		}		
		sort(b+1,b+1+n);
		int tot = unique(b+1,b+1+n)-b-1;
		cnt = 0,rt[0] = 0;
		for(int i = 1;i<=n;i++){
			update(rt[i],rt[i-1],1,tot,lower_bound(b+1,b+1+tot,a[i])-b);
		}
		int l,r,h;
		while(m--){
			scanf("%d%d%d",&l,&r,&h);
			l++,r++;
			int k=upper_bound(b+1,b+tot+1,h)-b-1;
			if(k)
		    	printf("%d\n",query(rt[l-1],rt[r],1,tot,k));
		    else
		    	printf("0\n");//�ӵ㣡 
		}
	}	
	return 0;
}
