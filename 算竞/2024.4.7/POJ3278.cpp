#include<iostream>
#include<queue>

using namespace std;

int n,k;
int dir[3]={-1,1},vis[200005],step;

int main(){
	cin>>n>>k;
	queue<int> q;
	q.push(n);
	vis[n] = 1;
	int flag = 1;
	while(flag&&!q.empty()){
		int m = q.size();
		while(flag&&m--){
			int cur = q.front();
			if(cur==k){
				flag = 0;
				break;
			}
			q.pop();
			if(cur>100002||!vis[cur*2]){
				vis[cur*2]=1;
				q.push(cur*2);
			}
			for(int i = 0;i<2;i++){
				int tx = cur +dir[i];
				if(vis[tx])continue;
				vis[tx] =1;
				q.push(tx);
			}
		}		
		step++;
	}
	cout<<step-1<<endl;
	return 0;
}
