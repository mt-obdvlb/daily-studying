#include<iostream>
#include<vector>

using namespace std;

int n;
int arr[30005];
vector<int> out[30005];

int main(){
	cin>>n;
	for(int t,i = 1;i<=n;i++){
		scanf("%d",&t);
		arr[i]=t;
		for(int j = 1;j<i;j++){
			if(t>arr[j])out[j].push_back(i);
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<out[i].size();j++)ans+=out[out[i][j]].size();
	}
	cout<<ans<<endl;
	return 0;
}
