#include<bits/stdc++.h>

using namespace std;

string s,fa;
int tot = 0,tot2=0,faa[50005];

int get(int x){
	return faa[x]==x?x:faa[x]=get(faa[x]);
}

int main(){
	map<string,int> mp;
	map<int,string> mp2;
	for(int i = 0;i<50005;i++)faa[i]=i;
	while(cin>>s){
		if(s=="$")return 0;
		if(s[0]=='#'){
		s.erase(s.begin());
			fa = s;	
			if(mp.find(fa)==mp.end())mp[fa]=++tot,mp2[++tot2]=fa;
		}else if(s[0]=='+'){
		s.erase(s.begin());
			if(mp.find(s)==mp.end())mp[s]=++tot,mp2[++tot2]=s;
			faa[mp[s]]=mp[fa];
		}else{
		s.erase(s.begin());
			cout<<s<<" "<<mp2[get(mp[s])]<<endl;
		}
		
	}
	
	return 0;
}
