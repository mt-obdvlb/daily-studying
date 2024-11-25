#include<bits/stdc++.h>

using namespace std;

int n;
double V[10005];
double C[10005];

int main(){
	scanf("%lf%lf%d",V,C,&n);
	vector<int> v;
	v.push_back(0);
	for(int i = 1;i<=n;i++){
		char c;
		getchar();
		scanf("%c",&c);
		switch(c){
			case 'P':{
				v.push_back(i);
				double v;
				double c;
				scanf("%lf%lf",&v,&c);
				double tv=V[i-1];
				double tc=C[i-1];
				V[i]=tv+v;
				double vv = v+tv;
				C[i]=tv*tc/vv+v*c/vv;
				break;
			}
			case 'Z':
				if(v.size()!=1)v.pop_back();
				int ind = v.back();
				V[i]=V[ind],C[i]=C[ind];
				break;
		}
	}
	for(int i = 1;i<=n;i++){
		printf("%.0lf %.5lf\n",V[i],C[i]);
	}
	return 0;
}
