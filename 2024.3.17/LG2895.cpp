#include<bits/stdc++.h> //美丽的万能头文件
using namespace std;
int n,ma[305][305],v[305][305],sx,sy,st,ans[305][305];//分别为陨石数量，陨石砸落地图，记录是否走过地图，陨石x,y坐标及砸落时间，每个点的最少时间图。
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};//方便移动和处理陨石砸落
int ch(int a){
	if (a==-1) return 99999;
	else return a;
}//判断路过该点时是否陨石已经砸落，如果是没有陨石，相当于n年后砸落
int main(){
    scanf("%d",&n);
    for (int i=0;i<305;i++){
    	for (int j=0;j<305;j++){
    		ma[i][j]=-1;
		}
	}//陨石初始化为-1
    for (int i=1;i<=n;i++){
    	scanf("%d%d%d",&sx,&sy,&st);//输入陨石
		for (int j=0;j<5;j++){//上下左右中标记陨石
			if (sx+dx[j]>=0&&sy+dy[j]>=0&&(ma[sx+dx[j]][sy+dy[j]]==-1||ma[sx+dx[j]][sy+dy[j]]>st))//如果该标记x,y坐标大于0且该点没有被陨石砸落或已标记时间没有该时间早，标记陨石
				ma[sx+dx[j]][sy+dy[j]]=st;
		} 
	}
	queue<int> q[2];//构造队列，存储将处理点x,y坐标
	v[0][0]=1;//初始点设为已走过
	q[0].push(0);q[1].push(0);//初始点放入队列
	while (!q[0].empty()){//只要队列不为空
		int x=q[0].front(),y=q[1].front();//提取将处理点x,y坐标
		q[0].pop();q[1].pop();//删除已处理点
		int s=ans[x][y]+1;//即将标记的点时间是现在点的下一个单位
		if (ma[x][y]==-1){ //如果该点安全，输出即将标记的点的时间-1
			printf("%d\n",s-1);
			return 0;
		}
		for (int i=1;i<=4;i++){
			int xx=x+dx[i],yy=y+dy[i];//提取将处理点的坐标
			if (xx>=0&&yy>=0&&s<ch(ma[xx][yy])&&v[xx][yy]==0){//将处理点需要x,y坐标大于等于0且该点没有走过并且陨石降落时间小于现时间
				q[0].push(xx);q[1].push(yy);//放入将处理队列
				v[xx][yy]=1;//标记已走过
				ans[xx][yy]=s;//将该点时间放入数组
			}
		}
	}
	printf("-1\n");//如果出不了陨石区，输出-1
	return 0;
}
