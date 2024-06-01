#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+10;
int node[N][26],fail[N],val[N],cnt=1;
char s[N];

void ins(const char *s){
	int p = 1;
	for(int i = 0;s[i];i++){
		int ind = s[i]-'a';
		if(!node[p][ind])node[p][ind]=++cnt;
		p = node[p][ind];
	}
	val[p]++;
}

void build(){
	queue<int> q;
	q.push(1);
	int p;
	while(!q.empty()){
		int cur= q.front();q.pop();
		for(int i = 0;i<26;i++){
			if(!node[cur][i]){
				if(!fail[cur])node[cur][i]=1;
				else node[cur][i] = node[fail[cur]][i];
			}else{
				p = fail[cur];
				if(!p)p=1;
				else p = node[p][i];
				fail[node[cur][i]]=p;
				q.push(node[cur][i]);
			}
		}
	}
}

int find_all(const char *s){
	int ret = 0,p=1,q;
	for(int i = 0;s[i];i++){
		int ind = s[i]-'a';
		p = node[p][ind];
		q = p;
		while(q&&~val[q]){
			ret+=val[q];
			val[q]=-1;
			q = fail[q];
		}
	}
	return ret;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		scanf("%s",s);
		ins(s); 
	}
	build();
	scanf("%s",s);
	cout<<find_all(s)<<endl;
	return 0; 
}
