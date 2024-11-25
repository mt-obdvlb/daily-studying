#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>


using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>x(n),y(n);
	for(int i = 0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	int X = 0,Y = 0,costX = 0,costY = 0;
	sort(x.begin(),x.end());
	for(int i = 0;i<n;i++){
		x[i] -= i;
	}
	sort(x.begin(),x.end());
	X = x[n/2];
	for(int i = 0;i<n;i++){
		costX += abs(x[i] - X);
	}
	sort(y.begin(),y.end());
	Y = y[n/2]; 
	for(int i = 0;i<n;i++){
		costY += abs(y[i]-Y);
	}
	cout<<costX + costY<<endl;
	return 0;
}
