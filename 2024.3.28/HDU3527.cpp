#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;



int main(){
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c)){
		string s;
		unordered_set<string> h1,h2;
		for(int i = 0;i<a;i++){
			cin>>s;
			h1.insert(s);
		}
		vector<string> v(b);
		for(int i = 0;i<b;i++){
			cin>>s;	
			if(h1.find(s)==h1.end())continue;
			v[i]=s;
			h2.insert(v[i]);		
		}
		for(int i =0 ;i<c;i++){
			cin>>s;
			if(h2.find(s)!=h2.end()){
				h2.erase(h2.find(s));
				for(int i = 0;i<v.size();i++){
					if(v[i]==s){
						v.erase(v.begin()+i);
						break;
					}
				}				
			}
		}
		if(v.size()==0)printf("No enemy spy\n");
		else{
			for(int i = 0;i<v.size();i++){
				if(i)cout<<" ";
				cout<<v[i];
			}
			printf("\n");
		}
		
	}
	return 0;
}
