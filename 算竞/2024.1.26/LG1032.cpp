#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

string a,b,from[10],to[10];
int cnt = 0,ans = 100,step_k;
unordered_map<string,int> dp;

void dfs(string &now,int step){
	if(step>step_k){
		return;
	}
	dp[now] = step;
	if(step>10){
		return;
	}
	if(step>=ans){
		return;
	}
	if(b == now){
		ans = step;
		return;
	}
	for(int i =0;i<cnt;i++){
		int pos = now.find(from[i]);
		string changed;
		while(pos !=-1){
			changed = now;
			changed.erase(pos,from[i].size());
			changed.insert(pos,to[i]);
			if(dp.find (changed)==dp.end()||step+1<dp[changed]){
				dfs(changed,step + 1);
			}
			pos = now.find(from[i],pos+1);
		}
	}
}

int main(){
	cin>>a>>b;
	while(cin>>from[cnt]>>to[cnt]){
		cnt++;
	}
	for(int i = 1;i<=10;i++){
		step_k = i;
		dp.clear();
		dfs(a,0);
		if(ans <=10){
			break;
		}
	}
	if(ans>10){
		cout<<"NO ANSWER!"<<endl;
	}else{
		cout<<ans<<endl;
	}
	return 0;
}
