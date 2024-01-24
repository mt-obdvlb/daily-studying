#include<iostream>
#include<vector>
#include<algorithm>

using  namespace std;


class UnionSet{
public:
	UnionSet(int n):fa(n+1),val(n+1){
		for(int i =0;i<=n;i++){
			fa[i] = i;
			val[i] = 0;
		}
	} 
	int get(int x){
		if(fa[x] == x){
			return x;
		}
		int root = get(fa[x]);
		val[x] = (val[x] + val[fa[x]] + 2)%2;
		return fa[x] = root;
	}
	void merge(int a,int b,int t){
		int aa = get(a),bb = get(b);
		if(aa == bb){
			return;
		}
		fa[aa] = bb;
		val[aa] = (t+val[b] -val[a] +2)%2;
	}
	vector<int> fa,val;
};

struct Data{
	int a,b,c;
};

int main(){
	int n,m;
	cin>> n>> m;
	UnionSet u(n);
	vector<Data> v(m);
	for(int i = 0;i<m;i++){
		Data &x = v[i];
		scanf("%d%d%d",&x.a,&x.b,&x.c);
	}
	sort(v.begin(),v.end(),[&](const Data &a,const Data &b)->bool{
		return a.c > b.c;
	});
	int ans = 0,flag = 1;
	for(int i = 0;i<m,flag;i++){
		int a = v[i].a,b = v[i].b,c = v[i].c;
		if(u.get(a) == u.get(b)){
			if((u.val[a] + u.val[b])%2 == 0){
				ans = c;
				flag = 0;
			}
		}else{
			u.merge(a,b,1);
		}
	}
	cout<< ans<< endl;
	return 0;
}
