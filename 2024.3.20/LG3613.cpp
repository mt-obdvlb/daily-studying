#include<iostream>
#include<vector>
using namespace std;

int n,q;

typedef pair<int,int> PII;

int main(){
	cin>>n>>q;
	vector<PII> arr[n+1];
	for(int i = 0;i<q;i++){
		int op;
		int ti,tj;
		cin>>op>>ti>>tj;
		if(op==1){
			
			int k;
			cin>>k;
			if(k==0){
				for(int j = 0;j<arr[ti].size();j++){
					if(arr[ti][j].first==tj){
						arr[ti].erase(arr[ti].begin()+j);
						break;
					}
				}
			}
			else arr[ti].push_back(PII(tj,k));
		}else{
			for(int j = 0;j<arr[ti].size();j++){
				if(arr[ti][j].first==tj){
					cout<<arr[ti][j].second<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
