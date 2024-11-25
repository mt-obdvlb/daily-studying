#include<iostream>

using namespace std;

int m,n;
int list[405];
int workitem[25][25];
int worktime[24][25];
int cnt[25];
int last[25];
bool vis[25][100000]={0};

bool check(int l,int r,int ma){
	for(int i = l;i<=r;i++){
		if(vis[ma][i])return false;
	}
	return true;
}

int main(){
	cin>>m>>n;
	for(int i = 1;i<=n*m;i++){
		cin>>list[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin>>workitem[i][j];
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin>>worktime[i][j];
		}
	}
	for(int i = 1;i<=n*m;i++){
		int now = list[i];
		cnt[now]++;
		int ma = workitem[now][cnt[now]];
		int ct = worktime[now][cnt[now]];
		for(int be = last[now]+1;;be++){
			if(check(be,be+ct-1,ma)){
				for(int j = be;j<=be+ct-1;j++){
					vis[ma][j]=true;
				}
				last[now]=be+ct-1;
				break;
			}
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++)ans=max(ans,last[i]);
	cout<<ans<<endl;
	return 0;
}
