#include<iostream>
#include<vector>

using namespace std;

class Unionset{
public:
	Unionset(int n):val(n +1),fa(n+1){
		for(int i = 0;i<=n;i++){
			val[i] = 0;
			fa[i] = i;
		}
	}
	int get(int x){
		if(fa[x] == x){
			return x;
		}
		int root = get(fa[x]);
		val[x] = (val[fa[x]]+val[x] +3)%3;
		return fa[x] = root;
	}
	void merge(int a,int b,int t){
		int aa = get(a),bb = get(b);
		if(aa == bb){
			return;
		}
		fa[aa] = bb;
		val[aa] = (t + val[b] - val[a] +3)%3;
	}
	
	vector<int> val,fa;
};


int main(){
	int n,m;
	cin>> n>> m;
	Unionset u(n);
	for(int a,b,c,i = 0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(a == 1){
			u.merge(b,c,2);
		}else{
			if(u.get(b)!=u.get(c)){
				printf("Unknown\n");
			}else{
				switch((u.val[b]-u.val[c]+3)%3){
					case 0:
						printf("Tie\n");
						break;
					case 1:
						printf("Loss\n");
						break;
					case 2:
						printf("Win\n");
						break;
				}
			}
		}
	}
	return 0;
}
