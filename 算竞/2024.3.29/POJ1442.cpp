#include<algorithm>
#include<set>
#include<iostream>
#include<ctime>

using namespace std;
int arr[30005];

struct Treap{
	int c[2];
	int key,rank,size;
	bool operator<(Treap& t){
		return rank<t.rank;
	}
	int cmp(int val){
		return (key>val)?0:1;
	}
}tr[60005];
int tot=0,rt = 0;

void update(int &o){
//	cout<<" key:"<<tr[o].key<<" "<<tr[o].size<<" ->";
	tr[o].size=1;
	if(tr[o].c[0])tr[o].size+=tr[tr[o].c[0]].size;
	if(tr[o].c[1])tr[o].size+=tr[tr[o].c[1]].size;
//	cout<<tr[o].size<<endl;
}
void rotate(int &o,int d){//0 left 1 right
	int t = tr[o].c[d^1];
	tr[o].c[d^1] = tr[t].c[d];
	tr[t].c[d] = o;
	update(o);
	update(t);
	o = t;
}


void ins(int &o,int val){
	if(!o){
		o = ++tot;
		tr[o].c[0]=tr[o].c[1]=0;
		tr[o].key = val;
		tr[o].size=1;
		tr[o].rank=(unsigned int)(rand());
		return;
	}
	/*if(tr[o].val==val){
		tr[o].size++;
		tr[o].cnt++;
		return;	
	}*/
	int d = tr[o].cmp(val);
	ins(tr[o].c[d],val);
	update(o);
	if(tr[o]<tr[tr[o].c[d]])rotate( o , d ^ 1);
}


int kth(int &o,int k){	
	int ls = tr[o].c[1]?tr[tr[o].c[1]].size:0;
	if(k==ls+1)return tr[o].key;
	else if(ls>=k)return kth(tr[o].c[1],k);
	else{
		return kth(tr[o].c[0],k-ls-1);
	}
}

int main(){
	//srand(time(NULL));
	ios::sync_with_stdio(false);
	multiset<int> s;
	int m,n,i=0;
	scanf("%d%d",&m,&n);
	for(int i = 0;i<m;i++)scanf("%d",arr+i);
	int cnt = 0;
	while(n--){
		int t;
		scanf("%d",&t);
		i++;
		while(cnt<t){
			ins(rt,arr[cnt++]);
		}
//		cout<<endl<<endl;
//		cout<<rt<<endl;
//		for(int i = 1;i<=cnt;i++)cout<<i<<" size:"<<tr[i].size<<" rank:"<<tr[i].rank<<" key:"<<
//	tr[i].key<<" "<<tr[i].c[0]<<" "<<tr[i].c[1]<<endl;
//		cout<<endl<<endl;
		printf("%d\n",kth(rt,cnt-i+1));
	}
/*	cout<<rt<<endl;
	for(int i = 1;i<=cnt;i++)cout<<i<<" size:"<<tr[i].size<<" rank:"<<tr[i].rank<<" key:"<<
	tr[i].key<<" "<<tr[i].c[0]<<" "<<tr[i].c[1]<<endl;
	for(int i = 1;i<=cnt;i++)cout<<kth(rt,i)<<endl;
*/	return 0;
}
