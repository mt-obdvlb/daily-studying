#include<bits/stdc++.h>

using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;
	long long ans = 0;
	for(int i = 0;i<s1.size();i++){
		for(int j = 1;j<s2.size();j++){
			if(s1[i]==s2[j]&&s1[i+1]==s2[j-1])ans++;
		}
	}
	cout<<(1<<ans)<<endl;
	return 0;
}
