#include<iostream>

using namespace std;

int n;
int arr[100005];
int Aarr[100005];

int main(){
	cin>>n;
	int preX,preY;
	int curX,curY;
	int ind;
	cin>>preX>>preY>>curX>>curY;
	arr[1]=abs(curX-preX)+abs(curY-preY);
	int ans=arr[1],tmp=0;
	for(int x,y,i = 2;i<n;i++){
		scanf("%d%d",&x,&y);
		arr[i]=abs(x-curX)+abs(y-curY);
		ans+=arr[i];
		Aarr[i]=-abs(x-preX)-abs(y-preY)+arr[i]+arr[i-1];
		if(Aarr[i]>tmp){
			tmp = Aarr[i];
			ind = i;
		}
		preX=curX,preY=curY,curX=x,curY=y;
	}
	cout<<ans-tmp<<endl;
	return 0;
}
