#include<bits/stdc++.h>

using namespace std;
const int L = 16;
const int inf = 0x7fffffff;
struct Node{
	int val,sum[L];
	struct Node *fw[L];
};
Node* head,*update[L];
int tot[L],total,ans;
int n,Min,add,level;

int getrandlay(){
	int lay=0;
	while(rand()&1&&lay<L-1)lay++;
	return lay;
}

int find(int val){
	Node* p = head;
	tot[level]=0;
	for(int i = level;i>=0;i--){
		while(p->fw[i]&&p->fw[i]->val<val)
			tot[i]+=p->sum[i],p=p->fw[i];
		if(i)tot[i-1]=tot[i];
		update[i]=p;
	}
	return tot[0];
}

void ins(int val){
	int lay = getrandlay();
	if(lay>level){
		for(int i = level+1;i<=lay;i++){
			head->sum[i]=total;
		}
		level = lay;
	}
	find(val);
	Node* p,*s;
	s = new Node;
	s->val = val;
	for(int i = 0;i<L;i++){
		s->fw[i]=NULL;
		s->sum[i]=0;
	}
	for(int i = 0;i<=lay;i++){
		s->fw[i] = update[i]->fw[i];
		update[i]->fw[i] = s;
		s->sum[i] = update[i]->sum[i]-(tot[0]-tot[i]);
		update[i]->sum[i]-=s->sum[i]-1;
	} 
	for(int i = lay+1;i<=level;i++)update[i]->sum[i]++;
}

int del(int val){
	int sum = find(val);
	for(int i = 0;i<=level;i++){
		head->fw[i]=update[i]->fw[i];
		head->sum[i]=update[i]->sum[i]-(tot[0]-tot[i]);
	}
	while(level>0&&!head->fw[level])level--;
	return sum;
}

void init(){
	level=add=0;
	head = new Node;
	head->val=-inf;
	for(int i = 0;i<L;i++){
		head->fw[i]=NULL;
		head->sum[i]=0;
	}
}

int kth(int k){
	Node* p = head;
	for(int i = level;i>=0;i--){
		while(p&&p->sum[i]<k){
			k-=p->sum[i];
			p=p->fw[i];
		}
	}
	return p->fw[0]->val;
}

int main(){
	char opt[5];
	int k;
	scanf("%d%d",&n,&Min);
	init();
	total = ans =add=0;
	int sum;
	while(n--){
		scanf("%s%d",opt,&k);
		switch(opt[0]){
			case 'I':
				if(k>=Min)ins(k-add),total++;
				break;
			case 'A':
				add+=k;
				break;
			case 'S':
				add-=k;
				sum=del(Min-add);
				ans+=sum;
				total-=sum;
				break;
			case 'F':
				if(k>total)printf("-1\n");
				else printf("%d\n",kth(total-k+1)+add);
		}
	}
	printf("%d\n",ans);
	return 0;
} 
