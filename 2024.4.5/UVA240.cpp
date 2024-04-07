#include<bits/stdc++.h>

using namespace std;

struct Node{
	int freq,val,cd;
	Node(int x,int y,int z):freq(x),val(y),cd(z){
	}
	bool operator<(const Node& b)const{
		if(freq!=b.freq)return freq>b.freq;
		return val>b.val;
	}
};

int tot=1,c,r,n,f[5000],N,tlen,stlen,fa[5000],code[5000];
string s;

priority_queue<Node> q; 

int main(){
	while(cin>>r&&r){
		cin>>N;
		memset(f,0,sizeof(f));
		stlen = 0; 
		for(int i = 0;i<N;i++){
			cin>>f[i];
			stlen+=f[i];
		}
		n = N;
		while((n-r)%(r-1)!=0)n++;
		while(!q.empty())q.pop();
		for(int i = 0;i<n;i++)q.push(Node(f[i],i,i));
		c = n;
		tlen = 0;
		while(q.size()!=1){
			int tsum = 0,minV = n;
			for(int i = 0;i<r;i++){
				tsum += q.top().freq;
				minV = min(minV,q.top().val);
				code[q.top().cd] = i;
				fa[q.top().cd] = c;
				q.pop();
			}
			q.push(Node(tsum,minV,c));
			tlen+=tsum;
			c++;
		}
		c--;
		printf("Set %d; average length %0.2lf\n",tot,1.0*tlen/stlen);
		for(int i = 0;i<N;i++){
			s.clear();
			int cur = i;
			while(cur!=c){
				s.push_back((char)(code[cur]+'0'));
				cur = fa[cur];
			}
			reverse(s.begin(),s.end());
			cout<<"    "<<char('A'+i)<<": "<<s<<endl;
		}
		tot++;
		cout<<endl;
	}
	return 0;
}
