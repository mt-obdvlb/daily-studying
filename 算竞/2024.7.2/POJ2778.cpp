#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 105;
const int K = 4;
const int MOD = 1e5+5; 
typedef long long ll;
struct mat{
	int a[N][N];
	mat(){
		memset(a,0,sizeof(a));
	}
};
int rt,L;

mat mul(mat A,mat B){
	mat ret;
	for(int i = 0;i<L;i++){
		for(int j = 0;j<L;j++){
			for(int k = 0;k<L;k++){
				ret.a[i][j] = (ret.a[i][j]+(ll)A.a[i][k]*B.a[k][j])%MOD;
			}
		}
	}
	return ret;
}

mat pow(mat A,int n){
	mat ans;
	for(int i = 0;i<L;i++)ans.a[i][i]=1;
	while(n>0){
		if(n&1)ans=mul(ans,A);
		A = mul(A,A);
		n>>=1; 
	}
	return ans;
}

int nxt[N][K],fail[N],ed[N],id[N];
int mp[256];


int getnewnode(){
	for(int i = 0;i<K;i++)nxt[L][i]=-1;
	ed[L]=0;
	return L++;
}

void init(){
	mp['A']=0,mp['C']=1,mp['T']=2,mp['G']=3;
	L=0;
	rt = getnewnode();
}

void ins(char *s){
	int len = strlen(s);
	int p = rt;
	for(int i = 0;i<len;i++){
		int ch = mp[s[i]];
		if(nxt[p][ch]==-1)nxt[p][ch]=getnewnode();
		p = nxt[p][ch];
	}
	ed[p]++;
}

void build_ac(){
	queue<int> q;
	fail[rt] = rt;
	for(int i = 0;i<K;i++){
		if(nxt[rt][i]==-1)nxt[rt][i]=rt;
		else{
			fail[nxt[rt][i]]=rt;
			q.push(nxt[rt][i]);
		}
	}
	while(!q.empty()){
		int now =  q.front();q.pop();
		if(ed[fail[now]])ed[now]++;
		for(int i = 0;i<K;i++){
			if(~nxt[now][i]){
				fail[nxt[now][i]]=nxt[fail[now]][i];
				q.push(nxt[now][i]);
			}else{
				nxt[now][i] = nxt[fail[now]][i];
			}
		}
	}
}

int query(int n){
	mat f;
	int ids = 0;
	memset(id,-1,sizeof(id));
	for(int i = 0;i<L;i++)
		if(!ed[i])id[i]=ids++;
	for(int u = 0;u<L;u++){
		if(ed[u])continue;
		for(int j = 0;j<K;j++){
			int v = nxt[u][j];
			if(!ed[v])f.a[id[u]][id[v]]++;
		}
	}
	L = ids;
	f = pow(f,n);
	int res = 0;
	for(int i = 0;i<L;i++)res = (res+f.a[0][i])%MOD;
	return res;
}

int main(){
	int m,n;
	char s[20];
	while(~scanf("%d%d",&m,&n)){
		init();
		while(m--){
			scanf("%s",s);
			ins(s);	
		}
		build_ac();
		cout<<query(n)<<endl;
	}
	return 0;
}
