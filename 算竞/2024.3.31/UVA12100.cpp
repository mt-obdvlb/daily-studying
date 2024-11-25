#include<bits/stdc++.h>

using namespace std;

int t,n,m,flag,ans;

typedef pair<int,int> PII;

int main(){
	cin>>t;
	priority_queue<int> pq;
	queue<PII> q;
	while(t--){
		flag = 1;
		ans = 0;
		while(!q.empty())q.pop();
		while(!pq.empty())pq.pop();
		scanf("%d%d",&n,&m);
		for(int tmp,i = 0;i<n;i++){
			scanf("%d",&tmp);
			q.push(PII(tmp,i)),pq.push(tmp);
		}
		while(flag){
			int cur_val = q.front().first,cur_ind = q.front().second;
			q.pop();
			if(cur_val == pq.top()){
				ans++;
				pq.pop();
				if(cur_ind==m){
					printf("%d\n",ans);
					flag = 0;
				}
			}else{
				q.push(PII(cur_val,cur_ind));
			}
		}
	}
	
	return 0;
}
