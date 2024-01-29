#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Data{
	int x,d,ind;
};

int ans[100005];

int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	vector<Data> v(n);
	for(int i = 0;i<n;i++){
		scanf("%d%d",&v[i].x,&v[i].d);
		v[i].ind = i;
	}
	sort(v.begin(),v.end(),[&](const Data  &a,const Data &b)->bool{
		return a.x<b.x;
	});
	while(t&&!v.empty()){
		while((v.front()).x==-1){
			Data &tmp = v.front();
			tmp.x-=t;
			v.erase(v.begin());
		}
		while((v.back()).x==-1){
			Data &tmp = v.back();
			tmp.x+=t;
			v.pop_back();
		}
		v[0].x+=v[0].d;
		for(int i = 1;i<v.size();i++){
			v[i].x+=v[i].d;
			if(v[i-1].x>=v[i].x){
				v[i-1].d = -1;
				v[i].d = 1;
        	}
			if(v[i-1].x>v[i].x){
				v[i-1].x+=v[i-1].d;
				v[i].x+=v[i].d;
			}
			if(i>=2&&v[i-2].x==v[i-1].x){
				v[i-2].d = -1;
				v[i-1].d = 1;
			}
		}
		t--;
	}
	for(int i = 0;i<n;i++){
		ans[v[i].ind] = v[i].x;
	}
	for(int i = 0;i<n;i++){
		if(i)printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}
