#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int arr[10005];
multiset<int> s;
int cnt = 1,tot=0;

int main(){
	int Max,n,mode = 1;
	scanf("%d%d",&Max,&n);
	for(int i = 0;i<n;i++){
		scanf("%d",arr+i);
	}
	sort(arr,arr+n);
	getchar();
	char op;
	while(op=getchar()){
		if(op=='e')break;
		switch(op){
			case 'a':
				int x;
				scanf("%d",&x);
				if(x>Max)break;
				s.insert(x);
				break;
			case 'r':
				cnt++;
				if(s.empty()){
					cout<<-1<<endl;
					break;
				}
				if(mode==2){
					
					if(cnt==arr[tot]){
					cout<<*s.rbegin()<<endl;
						tot++;
					}
					s.erase(*s.rbegin());
				}else{
					if(cnt==arr[tot]){
					cout<<*s.begin()<<endl;
						tot++;
					}
					s.erase(*s.begin());
				}		
				break;
			case 'p':
				scanf("%d",&mode);
		}
		getchar();
	}
	
	return 0;
}
