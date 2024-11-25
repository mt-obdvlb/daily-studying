#include<bits/stdc++.h>

using namespace std;

int n1,n2,n;
int x;
double sum;

int main(){
	while(cin>>n1>>n2>>n&&n){
		priority_queue<int> q1;
		priority_queue<int,vector<int>,greater<int>> q2;
		sum = 0;
		for(int i=0;i<n;i++){
			cin>>x;
			sum+=x;
			q1.push(x);
			q2.push(x);
			if(q1.size()>n2)
		   		q1.pop();
			if(q2.size()>n1)
				q2.pop();
		}
		while(!q1.empty()){
			sum-=q1.top();
			q1.pop();
		}
		while(!q2.empty()){
			sum-=q2.top();
			q2.pop();
		}
		
		printf("%.6lf\n",sum/(n-n1-n2));
	}
	
	return 0;
}
