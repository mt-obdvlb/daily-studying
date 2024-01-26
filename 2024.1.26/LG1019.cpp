#include<iostream>
#include<string>

#define MAX_N 25


using namespace std;

string s[MAX_N];
int ans = 0;
int d[MAX_N][MAX_N] = {0};
int vis[MAX_N] = {0};

int f(string &a,string &b){
	for(int i = a.size()-1;i>1;i--){
		int flag = 1;
		for(int j = 0;j<a.size()-i;j++){
			if(a[i+j]!=b[j]){
				flag = 0;
				break;
			}
			if(j == b.size()-1){
				return 0;
			}
		}
		if(flag){
			return a.size() - i;
		}
	}
	return 0;
}

void dfs(int ind,int n,int sum){
	vis[ind]++;
	ans = max(ans,sum);
	for(int i = 0;i<n;i++){
		if(d[ind][i] == 0){
			continue;
		}
		if(vis[i] == 2){
			continue;
		}
		dfs(i,n,sum+s[i].size()-d[ind][i]);
	}
	vis[ind]--;
}

int main(){
	int n;
	char start;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> s[i];
	}
	cin >> start;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			d[i][j] = f(s[i],s[j]);
		}
	}
	for(int i = 0;i<n;i++){
		if(s[i][0]!=start){
			continue;
		}
		dfs(i,n,s[i].size());
	}
	cout<< ans << endl;
	return 0;
} 
