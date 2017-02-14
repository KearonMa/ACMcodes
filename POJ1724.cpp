#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int k,n,r;
struct road{
 int e,l,c;
};
vector <vector<road> > citymap(110);
int minLen=inf;
bool visited[110];
int totalLen;
int totalCost;
int minL[110][10110];

void dfs(int s)
{
    if(s==n)
    {
        if(minLen>totalLen)
            minLen=totalLen;
        return;
    }
    for(int i=0;i<citymap[s].size();i++)
    {
        int e=citymap[s][i].e;
        if(!visited[e])
        {
            int cost=totalCost+citymap[s][i].c;
            if(cost>k)
                continue;
            if(totalLen+citymap[s][i].l>=minLen)
                continue;
            if(totalLen+citymap[s][i].l>=minL[e][cost])
                continue;
            totalLen+=citymap[s][i].l;
            totalCost=cost;
            minL[e][cost]=totalLen;
            visited[e]=1;
            dfs(e);
            visited[e]=0;
            totalLen-=citymap[s][i].l;
            totalCost-=citymap[s][i].c;
        }
    }
}
int main()
{
    cin>>k>>n>>r;
    for(int i=0;i<r;i++)
    {
        int s;
        road r;
        cin>>s>>r.e>>r.l>>r.c;
        citymap[s].push_back(r);
    }
    memset(visited,0,sizeof(visited));
    memset(minL,inf,sizeof(minL));
    totalCost=0;
    totalLen=0;
    dfs(1);
    if(minLen!=inf)
        cout<<minLen<<endl;
    else
        cout<<-1<<endl;
}
