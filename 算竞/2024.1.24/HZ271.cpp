#include<iostream>
#include<vector>
#include<deque>

using namespace std;


int main(){
	int n,k,cnt = 0;
	cin >> n >> k;
	vector<int> v(n);
	deque<int> Dmin;
	deque<int> Dmax;
	int ans1[n];
	int ans2[n];
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	for(int i = 0,j = 0;i<n;i++){
		if(i-j>=k){
			if(Dmin.front()==v[j]){
				Dmin.pop_front();
			}
			if(Dmax.front()==v[j]){
				Dmax.pop_front();
			}
			j++;
		}
		while(!Dmin.empty()&&Dmin.back()>v[i]){
			Dmin.pop_back();
		}
		Dmin.push_back(v[i]);
		while(!Dmax.empty()&&Dmax.back()<v[i]){
			Dmax.pop_back();
		}
		Dmax.push_back(v[i]);
		if(i>=k-1){
			ans1[cnt] = Dmin.front();
			ans2[cnt++] = Dmax.front();
		}
	}
	for(int i = 0;i<cnt;i++){
		if(i){
			cout<<" ";
		}
		cout<< ans1[i];
	}
	cout<<endl;
	
	for(int i = 0;i<cnt;i++){
		if(i){
			cout<<" ";
		}
		cout<< ans2[i];
	}
	cout<<endl;
	return 0;
} 
