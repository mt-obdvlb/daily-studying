/*************************************************************************
	> File Name: POJ1521.cpp
	> Author: mtobdvlb 
	> Mail:mtobdvlb@163.com 
	> Created Time: Tue 02 Apr 2024 06:22:02 PM CST
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<cstdlib>
#include<string>
#include<cstring>
#include<list>
#include<bits/stdc++.h>
#include<numeric>
using namespace std;

int main(){
    string s;
    int n,arr[256];
    while(cin>>s){
        if(s=="END")return 0;
        n = s.size();
        priority_queue<int,vector<int>,greater<int> >q;
        memset(arr,0,sizeof(arr));
        for(int i = 0;i<n;i++){
            arr[s[i]]++;
        }
        for(int i = 0;i<256;i++){
            if(arr[i]==0)continue;
            q.push(arr[i]);
        }
        int ans =n ;
         while(q.size()>2){
            int t,t1,t2;
			t1=q.top(),q.pop();
			t2=q.top(),q.pop();
			t=t1+t2;
			ans+=t;
            q.push(t);
        }
        printf("%d %d %.1lf\n",n*8,ans,(double)n*8/ans);
    }  
    return 0;
}
