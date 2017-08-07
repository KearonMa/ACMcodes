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
    for(int i=0;i<M;i++)
        E[i].clear();
}
