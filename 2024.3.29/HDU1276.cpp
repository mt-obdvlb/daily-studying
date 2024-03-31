#include<iostream>
#include<list>

using namespace std;

typedef pair<int,int> PII;

int main(){
	int t;
	list<int> l;
	cin>>t;
	while(t--){
		int n;
		l.clear();
		scanf("%d",&n);
		for(int i = 1;i<=n;i++)l.push_back(i);
		int k = 2;
		while(l.size()>3){
			int cnt = 1;
			for(list<int>::iterator it = l.begin();it!=l.end();){
				if(cnt++%k==0){
					it=l.erase(it);
				}else{
					it++;
				}
			}
			k=(k==2?3:2); 
		}
		list<int>::iterator it = l.begin();
		while(it!=l.end()){
			cout<<*it<<" ";
			it++;
		}
		cout<<endl;
	}
	return 0;
}
