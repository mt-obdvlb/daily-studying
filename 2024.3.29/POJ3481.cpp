#include<iostream>
#include<map>
using namespace std;

map<int,int> m;

int main(){
	int op;
	map<int,int>::iterator it;
	while(~scanf("%d",&op)){
		if(op==0)break;
		int k,p;
		switch(op){
			case 1:
				scanf("%d%d",&k,&p);
				m[p]=k;
				break;	
			case 2:
				if(m.empty()){
					printf("0\n");
					break;
				}
				it = --m.end();
				printf("%d\n",it->second);
				m.erase(it);
				break;
			case 3:
				if(m.empty()){
					printf("0\n");
					break;
				}
				it = m.begin();
				printf("%d\n",it->second);
				m.erase(it);
				break;
		}
	}
	return 0;
}
