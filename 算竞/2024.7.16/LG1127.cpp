#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,i,letter[27],in[27],out[27],fa[27],set_count;
int Eular_start,Eular_end;
int vis[1002];
string s[1002],res[1002];
int ch_start,ch_end,stf,edf;
int find(int x)
{
    if(fa[x]!=x)return fa[x]=find(fa[x]);
    return fa[x];
}
void unionn(int x,int y)
{
    fa[y]=x;
    return;
}
struct node
{
    int to,ord;
    string word;
};
vector<vector<node> >E;
bool cmp(string a,string b)
{
    return a<b;
}
void dfs(int st,int now,int pre_edge)
{
    if(st==n)
    {
        for(i=1;i<=n;i++)
        {
            cout<<res[i];
            if(i<n)cout<<".";
        }
        exit(0);
    }
    for(int k=0;k<E[now].size();k++)
    {
        if(!vis[E[now][k].ord])
        {
            vis[E[now][k].ord]=1;
            res[st+1]=E[now][k].word;
            dfs(st+1,E[now][k].to,E[now][k].ord);
        }
    }
    vis[pre_edge]=0;
    return;
}
int main()
{
    cin>>n;
    E.resize(27);
    for(i=1;i<=n;i++)cin>>s[i];
    sort(s+1,s+n+1,cmp);
    for(i=1;i<=n;i++)
    {
        ch_start=s[i][0]-'a'+1;
        ch_end=s[i][s[i].length()-1]-'a'+1;
        out[ch_start]++;
        in[ch_end]++;
        if(!letter[ch_start])
        {
            set_count++;
            letter[ch_start]=1;
            fa[ch_start]=ch_start;
        }
        if(!letter[ch_end])
        {
            set_count++;
            letter[ch_end]=1;
            fa[ch_end]=ch_end;
        }
        if(ch_start!=ch_end)
        {
            stf=find(ch_start);
            edf=find(ch_end);
            if(stf!=edf)
            {
                set_count--;
                unionn(stf,edf);
            }
        }
        node tmp;
        tmp.to=ch_end;
        tmp.ord=i;
        tmp.word=s[i];
        E[ch_start].push_back(tmp);
    }
    if(set_count!=1)
    {
        cout<<"***";
        return 0;
    }
    for(i=1;i<=26;i++)
    {
        if(!letter[i])continue;
        if(out[i]==in[i]+1)
        {
            if(Eular_start)
            {
                cout<<"***";
                return 0;
            }
            Eular_start=i;
        }
        else if(in[i]==out[i]+1)
        {
            if(Eular_end)
            {
                cout<<"***";
                return 0;
            }
            Eular_end=i;
        }
        else if(in[i]==out[i])continue;
        else
        {
            cout<<"***";
            return 0;
        }
    }
    if((Eular_start&&!Eular_end)||(!Eular_start&&Eular_end))
    {
        cout<<"***";
        return 0;
    }
    if(!Eular_start)Eular_start=s[1][0]-'a'+1;
    dfs(0,Eular_start,0);
    return 0;
}

