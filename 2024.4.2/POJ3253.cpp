/*************************************************************************
	> File Name: UVA3253.cpp
	> Author: mtobdvlb 
	> Mail:mtobdvlb@163.com 
	> Created Time: Tue 02 Apr 2024 05:53:50 PM CST
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
    int n;
    scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 1,t ;i<=n;i++){
       cin>>t,q.push(t); 
        
    }
    long long ans = 0;
    while(q.size()>1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans +=(a+b);
        q.push(a+b);
    }
    cout<<ans<<endl;
    return 0;
}
