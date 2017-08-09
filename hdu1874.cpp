#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int M=20010;
int dis[M],inq[M];
struct edge
{
    int v,w;
};
vector<edge> E[M];
int spfa(int s,int t,int n)
{
    memset(dis,0x3f,sizeof(dis));
    memset(inq,0,sizeof(inq));
    queue<int> q;
    dis[s]=0;
    q.push(s);
    inq[s]=1;
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=0;i<E[now].size();i++)
        {
            int v=E[now][i].v;
            int w=E[now][i].w;
            if(dis[v]>dis[now]+w)
            {
                dis[v]=dis[now]+w;
                if(!inq[v])
                {
                    q.push(v);
                    inq[v]=1;
                }
            }
        }
        inq[now]=0;
    }
    return dis[t];
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<n; i++)
            E[i].clear();
        for(int i=0; i<m; i++)
        {
            int a,b,x;
            scanf("%d%d%d",&a,&b,&x);
            E[a].push_back(edge{b,x});
            E[b].push_back(edge{a,x});
        }
        int s,e;
        scanf("%d%d",&s,&e);
        int ans=spfa(s,e,n);
        if(ans>=inf)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
}
