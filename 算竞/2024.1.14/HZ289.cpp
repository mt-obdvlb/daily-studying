#include<bits/stdc++.h>

using namespace std;

#define MAX_NUM 100000

typedef long long ll;
typedef pair<int,int> PII;

ll arr[MAX_NUM + 10] = {0};
int st[MAX_NUM + 10] = {0};
int l[MAX_NUM + 10] = {0},r[MAX_NUM +10] = {0};

void del(int x){
	r[l[x]] = r[x];
	l[r[x]] = l[x];
	st[x] = 1;
}

int main(){
	int n,m,k = 1;
	ll S = 0,cnt = 0;
	scanf("%d%d",&n,&m);
	scanf("%lld",arr+1);
	for(int i = 1,a;i<n;i++){
		scanf("%d",&a);
		if(1LL * arr[k] * a<0){
			arr[++k] = a;
		}else{
			arr[k] += a;
		}
	}
	set<PII> s;
	n = k;
	for(int i = 1;i<=n;i++){
		if(arr[i]>0){
			cnt+=1;
			S += arr[i];
		}
		s.insert(PII(abs(arr[i]),i));
		l[i] = i - 1;
		r[i] = i + 1;
	}
	while(cnt>m){
		while(st[s.begin()->second]){
			s.erase(s.begin());
		}
		int ind = s.begin()->second;
		s.erase(s.begin());
		int left = l[ind],right = r[ind];
		if((left>0&&right<=n)||arr[ind]>0){
			S -= abs(arr[ind]);
			arr[ind] += arr[left] + arr[right];
			s.insert(PII(abs(arr[ind]),ind));
			del(left);
			del(right);
			cnt-=1; 
		}
	}
	printf("%lld\n",S);
	return 0;
}
