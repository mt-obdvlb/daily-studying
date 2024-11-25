#include<iostream>
#include<string>
using namespace std;
int n,k,a[257],rest,t=1,minp,cnt=0;
bool flag=0;
string num;
int main(){
    cin>>num>>k;
    n=num.length();
    for(int i=1;i<=n;++i)a[i]=num[i-1]-'0';
    rest=n-k;
    while(cnt<rest){
        minp=t;
        for(int i=t;i<=k+t;++i)if(a[minp]>a[i])minp=i;
        if(a[minp])flag=1;
        if(flag)cout<<a[minp];
        k-=minp-t;
        t=minp+1;
        cnt++;
    }
    if(!flag)cout<<0;
    return 0;
}
