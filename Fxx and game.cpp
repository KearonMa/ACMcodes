#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN=1000005;
int vis[MAXN];
struct Step{
    int w;
    int steps;
    Step(int ww,int s):w(ww),steps(s){}
};
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        queue<Step> q;
        memset(vis,0,sizeof(vis));
        int x,k,t;
        scanf("%d%d%d",&x,&k,&t);
        q.push(Step(x,0));
        vis[x]=1;
        while(!q.empty())
        {
            Step s=q.front();
            if(s.w==1)
            {
                printf("%d\n",s.steps);
                break;
            }
            else
            {
                for(int i=1;i<=t;i++)
                {
                    if(s.w-i>=1&&!vis[s.w-i])
                    {
                        q.push(Step(s.w-i,s.steps+1));
                        //printf("W:%d %d\n",s.steps+1,s.w-i);
                        vis[s.w-i]=1;
                    }
                }
                if(k!=0&&!(s.w%k))
                    if(s.w/k>=1&&!vis[s.w/k])
                {
                    q.push(Step(s.w/k,s.steps+1));
                    //printf("!W:%d %d\n",s.steps+1,s.w/k);
                    vis[s.w/k]=1;
                }
                q.pop();
            }
        }
    }
}
