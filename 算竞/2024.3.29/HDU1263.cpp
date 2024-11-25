#include<iostream>
#include<map>
#include<string> 
using namespace std;


int n;

int main(){
	scanf("%d",&n);
	while(n--){
		int m;
		map<string,map<string,int> >mp; //二维map，注意空格！
		cin>>m;
		string name,place;
		int num;
		for(int i=0;i<m;i++){
           cin>>name>>place>>num;
           mp[place][name]+=num;
		}
		map<string,map<string,int> >::iterator iter1;
		map<string,int>::iterator iter2;
		for(iter1=mp.begin();iter1!=mp.end();iter1++){ //第一关键字
			cout<<iter1->first<<endl;
			for(iter2=iter1->second.begin();iter2!=iter1->second.end();iter2++) //第二关键字
				cout<<"   |----"<<iter2->first<<"("<<iter2->second<<")"<<endl;
		}
       if(n) cout<<endl;
	}
	return 0;
}
