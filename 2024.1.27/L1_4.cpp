#include<iostream>


using namespace std;

int main(){
	int n;
	cin>>n;
	double w[105],s,x[105];
	for(int i = 0;i<n;i++)cin>>w[i];
	cin>>s;
	for(int i = 0;i<n;i++)cin>>x[i];
	for(int i = 0;i<n;i++)s+=w[i]*x[i];
	if(s<=0) cout<<0<<endl;
	else printf("%.2lf",s);
	return 0;
}
