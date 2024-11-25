#include<bits/stdc++.h>
#include<numeric>

using namespace std;

int n;
int arr[100005];

int main(){
	cin>>n;
	multiset<int,greater<int>> s;
	for(int a,i = 0;i<n;i++){
		scanf("%d",&a);
		s.insert(a);
	}
	int ans = 0;
	while(s.size()>=2){
		int a= int(*s.begin());
		s.erase(s.begin());
		int b = int(*s.begin());
		s.erase(s.begin());
		ans+=a*b;
		s.insert(a);
	}
	cout<<ans<<endl;
	return 0;
}
