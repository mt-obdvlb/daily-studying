#include<bits/stdc++.h>

using namespace std;

int n,op,x;

int main(){
	cin>>n;
	set<int> se;
	set<int>::iterator it,it1,it2;
	while(n--){
		scanf("%d%d",&op,&x);
		if(op==1){
			if((se.insert(x)).second==false)printf("Already Exist\n");
		}else{
			if(se.empty())printf("Empty\n");
			else{
				it = se.lower_bound(x);
				if(it==se.end())it--,printf("%d\n",*it),se.erase(it);
				else{
					if(*it==x)printf("%d\n",x),se.erase(it);
					else{
						if(it==se.begin())printf("%d\n",*it),se.erase(it);
						else{
							it1 = it2 = it;
							it1--;
							if(x-*it1<=*it2-x)printf("%d\n",*it1),se.erase(it1);
							else printf("%d\n",*it2),se.erase(it2);
						}
					}
				}
			}
		}
	}
	return 0;
}
