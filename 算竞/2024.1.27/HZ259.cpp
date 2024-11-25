#include<iostream>
#include<algorithm>

using namespace std;

struct Data{
	int x,y;
}rob[100005],work[100005];

bool cmp(const Data& a,const Data &b){
	if(a.x!=b.x)return a.x>b.x;
	return a.y>b.y;
}

int main(){
	int n,m,cnt[105] = {0};
	cin>>n>>m;
	for(int i  =0;i<n;i++){
		scanf("%d%d",&rob[i].x,&rob[i].y);
	}
	for(int i  =0;i<m;i++){
		scanf("%d%d",&work[i].x,&work[i].y);
	}
	sort(rob,rob+n,cmp);
	sort(work,work+m,cmp);
	long long  ans = 0,sum=0;
	for(int i = 0,j = 0;i<m;i++){
		while(j<n&&rob[j].x>=work[i].x){
			cnt[rob[j].y]+=1;
			j+=1;
		}
		for(int y = work[i].y;y<=100;y++){
			if(cnt[y]==0)continue;
			cnt[y]-=1;
			ans+=1;
			sum+=(500*work[i].x+2*work[i].y);
			break;
		}
	}
	cout<<ans<<" "<<sum<<endl;
	return 0;
}
