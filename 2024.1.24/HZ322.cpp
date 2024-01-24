#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Unionset{
public:
	Unionset(int n):fa(n + 1) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
    vector<int> fa;
};

struct Data{
	int i,j,e;
};


void solve(){
	int n,cnt = 0;
	scanf("%d",&n);
	Unionset u(2*n);
	vector<Data> v(n);
	unordered_map<int,int> h;
	for(int j = 0;j<n;j++){
		scanf("%d%d%d",&v[j].i,&v[j].j,&v[j].e);
		if(h.find(v[j].i) == h.end()){
			h[v[j].i] = cnt++;
		} 
		if(h.find(v[j].j) == h.end()){
			h[v[j].j] = cnt++;
		}
	}
	for(int j = 0;j<n;j++){
		if(v[j].e == 0){
			continue;
		}
		u.merge(h[v[j].i],h[v[j].j]);
	}
	int flag = 1;
	for(int j  = 0;j<n;j++){
		if(v[j].e == 1){
			continue;
		}
		if(u.get(h[v[j].i]) == u.get(h[v[j].j])){
			flag = 0;
			break;
		}
	}
	if(flag){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
}

int main(){
	int t = 0 ;
	cin >> t;
	for(int i = 0;i<t;i++){
		solve();
	}
	return 0;
}
