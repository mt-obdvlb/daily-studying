#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int s[105],u[105],w[105][105] = {0};
int outdeg[105] ={0},indeg[105]={0};
int main(){
	int n,p;
	cin>>n>>p;
	vector<vector<int>> v(n+1);
	for(int i = 1;i<=n;i++){
		cin>>s[i]>>u[i];
		if(s[i]==0)s[i] = -u[i];
	}
	for(int a,b,c,i = 1;i<=p;i++){
		cin>>a>>b>>c;
		w[a][b] = c;
		indeg[b]++;
		outdeg[a]++;
		v[a].push_back(b);
	}
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(indeg[i]==0)q.push(i);
	}
	while(!q.empty()){
		int ind = q.front();
		q.pop();
		if(s[ind]>0){
			for(int i = 0;i<v[ind].size();i++){
				int to = v[ind][i];
				s[to] += w[ind][to]*s[ind];
			}	
		}
		for(int i = 0;i<v[ind].size();i++){
			int to = v[ind][i];
			indeg[to]--;
			if(indeg[to]==0){
				q.push(to);
			}
		}
	}
	int flag = 1;
	for(int i = 1;i<=n;i++){
		if(outdeg[i])continue;
		if(s[i]<=0)continue;
		cout<<i<<" "<<s[i]<<endl;
		flag = 0;
	}
	if(flag)cout<<"NULL"<<endl;
	return 0;
}
