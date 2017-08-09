#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=200010;
vector <pair<int ,int> > Edge[maxn]; //pair(v,len)
int dis[maxn];
int dijkstra(int n, int s, int e)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;
    priority_queue<pair<int, int> > q;
    q.push(make_pair(-dis[s], s));
    while(!q.empty())
    {
        int now = q.top().second;
        if(dis[now] < -q.top().first)
        {
            q.pop();
            continue;
        }
        q.pop();
        for(int i = 0; i < Edge[now].size(); i ++)
        {
            int v = Edge[now][i].first;
            int len = Edge[now][i].second;
            if(dis[v] > dis[now] + len)
            {
                dis[v] = dis[now] + len;
                q.push(make_pair(-dis[v], v));
            }
        }
    }
    if(dis[e] == inf) return -1;
    return dis[e];
}

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=0;i<=n;i++)
            Edge[i].clear();
        int a,b,w;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>w;
            Edge[a].push_back(make_pair(b,w));
            Edge[b].push_back(make_pair(a,w));
        }
        cin>>a>>b;
        cout<<dijkstra(n,a,b)<<endl;
    }
}
