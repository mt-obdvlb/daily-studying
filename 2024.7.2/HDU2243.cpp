#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
typedef unsigned long long ll;
const int K = 26;
const int N = 40;

struct mat{
	ll a[N][N];
	int n;
	mat(int n){
		this->n = n;
		memset(a,0,sizeof(a));
	}
};

mat mul(mat a,mat b){
	mat ret(a.n);
	for(int i = 0;i<a.n;i++){
		for(int j = 0;j<b.n;j++){
			for(int k = 0;k<a.n;k++){
				ret.a[i][j]+=a.a[i][k]*b.a[k][j];
			}
		}
	}
	return ret;
}

mat pow(mat a,int n){
	mat ret(a.n);
	for(int i = 0;i<a.n;i++)ret.a[i][i]=1;
	while(n){
		if(n&1)ret = mul(ret,a);
		a = mul(a,a);
		n>>=1;
	}
	return ret;
}

int nxt[N][K],fail[N],ed[N],id[N];
int rt,L;

int getnewnode(){
	for(int i = 0;i<K;i++)nxt[L][i]=-1;
	ed[L]=0;
	return L++;	
}

void init(){
	L=0;
	rt = getnewnode();
}

void ins(char *s){
	int t = rt;
	int len = strlen(s);
	for(int i = 0;i<len;i++){
		int x = s[i]-'a';
		if(nxt[t][x]==-1)nxt[t][x]=getnewnode();
		t = nxt[t][x];
	}
	ed[t]++;
}

void build_ac(){
	queue<int> q;
	fail[rt]=rt;
	for(int i = 0;i<K;i++){
		if(nxt[rt][i]==-1)nxt[rt][i]=rt;
		else{
			fail[nxt[rt][i]]=rt;
			q.push(nxt[rt][i]);
		}
	}
	while(!q.empty()){
		int now = q.front();q.pop();
		if(ed[fail[now]])ed[now]++;
		for(int i = 0;i<K;i++){
			if(~nxt[now][i]){
				fail[nxt[now][i]] = nxt[fail[now]][i];
				q.push(nxt[now][i]);
			}else{
				nxt[now][i] = nxt[fail[now]][i];
			}
		}
	}
}

ll query(int n){
	int ids = 0;
	memset(id,-1,sizeof(id));
	for(int i = 0;i<L;i++){
		if(!ed[i])id[i]=ids++;
	}
	mat f(ids+1);
	for(int u = 0;u<L;u++){
		if(ed[u])continue;
		for(int j = 0;j<K;j++){
			int v = nxt[u][j];
			if(!ed[v])f.a[id[u]][id[v]]++;
		}
	} 
	for(int i = 0;i<ids+1;i++)f.a[i][ids]=1;
	f = pow(f,n);
	ll ret = 0;
	for(int i = 0;i<L;i++)ret+=f.a[0][i];
	return --ret;
}

ll pow(int n){
	mat ret(2);
	ret.a[0][0]=26;
	ret.a[0][1]=ret.a[1][1]=1;
	ret = pow(ret,n);
	return ret.a[0][0]+ret.a[0][1]-1;
}

int main(){
	int n,m;
	char s[10];
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i = 0;i<n;i++){
			scanf("%s",s);
			ins(s);
		}
		build_ac();
		cout<<pow(m)-query(m)<<endl;
	}
	return 0;
}
