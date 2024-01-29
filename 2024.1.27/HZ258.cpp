#include<iostream>
#include<cinttypes>
#include<cstdlib>

using namespace std;

int arr[105][105] = {0};


int main(){
	int n= 0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin >> arr[i][j];
			arr[i][j] +=arr[i-1][j];
		}
	}
	int ans = INT32_MIN;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			int S = 0;
			for(int k = 1;k<=n;k++){
				int a = arr[j][k] - arr[i-1][k];
				if(S>=0){
					S+=a;
				}else{
					S=a;
				}
				ans = max(ans,S);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
