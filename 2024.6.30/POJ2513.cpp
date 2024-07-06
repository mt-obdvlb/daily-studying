#include<iostream>
#include<string>

using namespace std;
const int N = 5e5;
int trie[N][26],col[N],fa[N],cnt=1,deg[N],color=0,ed[N];

int get(int x){
	return fa[x]==x?x:fa[x] = get(fa[x]);
}

void merge(int a,int b){
	fa[get(a)] = get(b);
}

int ins(string s){
	int i,I,p = 1;
	for(i = 0,I = s.size();i<I;i++){
		int ind = s[i]-'a';
		if(!trie[p][ind])trie[p][ind]=++cnt;
		p = trie[p][ind];
	}
	if(ed[p])return col[p];
	ed[p]=1;
	return col[p] = ++color;
}

int main(){
	for(int i = 0;i<N;i++){
		fa[i]=i;
	}
	int i,j;
	string a,b;
	while(cin>>a>>b){
		i = ins(a);
		j = ins(b);
		deg[i]++,deg[j]++;
		merge(i,j);
	}
	int s = get(1);
	int tot = 0;
	for(int i = 1;i<=color;i++){
		if(deg[i]&1)tot++;
		if(get(i)!=s||tot>2){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	if(tot==0||tot==2) cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
	return 0;
}
