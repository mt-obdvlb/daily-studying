#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int t;

int main(){
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
		string s[105];
		char c[105];
		int ind[105]={0};
		int time[105]={0};
		for(int i = 0;i<n;i++){
			cin>>s[i];
			time[i]=(s[i][0]-'0')*600+(s[i][1]-'0')*60+(s[i][3]-'0')*10+(s[i][4]-'0');
			getchar();
			scanf("%c",&c[i]);
			getchar();
			ind[i]=i;
		}
		sort(ind,ind+n,[&](int i,int j)->bool{
			return time[i]<time[j];
		});
		int cnt = 0;
		for(int i = 0;i<n;i++){
			if(c[ind[i]]=='K'){
				if(cnt==0){
					cout<<s[ind[i]]<<" Kill"<<endl;
					cnt++;
				}else{
					if(time[ind[i]]-time[ind[i-1]]>10){
						cout<<s[ind[i]]<<" Kill"<<endl;
						cnt=0;
						break;
					}
					switch(cnt){
						case 1:
							cout<<s[ind[i]]<<" Double Kill"<<endl;
							cnt++;
							break;
						case 2:
							cout<<s[ind[i]]<<" Triple Kill"<<endl;
							cnt++;
							break;
						case 3:
							cout<<s[ind[i]]<<" Quadra Kill"<<endl;
							cnt++;
							break;
						case 4:
							cout<<s[ind[i]]<<" Penta Kill"<<endl;
							cnt++;
							break;
						case 5:
							cout<<s[ind[i]]<<" Penta Kill"<<endl;
							break;
					}
				}
			}else if(c[ind[i]]=='D'){
				cnt=0;
			}
		}
	}
	return 0;
}
