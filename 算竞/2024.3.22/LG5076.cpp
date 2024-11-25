#include<iostream>
#include<set>
using namespace std;

int q;

typedef multiset<int>::iterator it;

int main(){
	scanf("%d",&q);
	multiset<int> s;
	s.insert(0x7fffffff);
	s.insert(-0x7fffffff);
	while(q--){
		int op,x;
		scanf("%d%d",&op,&x);
		switch(op){
			case 1:{
				
				it i = s.lower_bound(x);
				int cnt = 0;
				for(it j = s.begin();j!=i;cnt++,j++){
				}
				printf("%d\n",cnt);
				break;
				break;
			}
			case 2:{
				int j = 0;
				it i; 
				for(i = s.begin();j<x;j++,i++);
				printf("%d\n",*i);
				break;
			}
				
				break;
			case 3:
				printf("%d\n",*(--(s.lower_bound(x))));
				break;
			case 4:
				printf("%d\n",*s.upper_bound(x));
				break;
			case 5:
				s.insert(x);
				break; 
		}
	}
	return 0;
}
