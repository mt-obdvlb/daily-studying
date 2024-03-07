#include<iostream>
#include<algorithm>

using namespace std;

#define S(x) ( ( x ) * ( x ) )

#define DIS(x1,y1,x2,y2) S( x1 - x2 )+S( y1 - y2 )

int x1,x2,y2,n;
int x[100005],y[100005],dis[100005],ind[100005];

int main(){
	int y1;
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	for(int i = 0;i<n;i++){
		scanf("%d%d",x+i,y+i);
		ind[i]=i;
	}
	sort(ind,ind+n,[&](int i,int j)->bool{
		return DIS(x1,y1,x[i],y[i])<DIS(x1,y1,x[j],y[j]);
	});
	for(int i = n-1;i>=0;i--){
		dis[i] = DIS(x2,y2,x[ind[i]],y[ind[i]]);
		dis[i] = max(dis[i+1],dis[i]);
	}
	int ans = dis[0];
	for(int i = 0;i<n;i++){
		ans = min(ans,DIS(x[ind[i]],y[ind[i]],x1,y1)+dis[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}
