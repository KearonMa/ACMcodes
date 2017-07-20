/*
2个人在环形的路上走，每分钟放下一个标记，问何时2个人的标记第一次出现重合。
直接模拟即可。注意题目需要一个人的标记与另一个人的标记重合
（与自己的标记重合不算），所以需要分开记录2个人的标记。
*/
#include <bits/stdc++.h>
using namespace std;
int vis[100005];
int main()
{
    int m;
    scanf("%d",&m);
    while(m--)
    {
        memset(vis,0,sizeof(vis));
        int n,d,r;
        scanf("%d%d%d",&n,&d,&r);
        int t=1;
        int dd=d%n;
        int rr=r%n;
        while(1)
        {
            if(vis[dd]==0)
            {
                vis[dd]=1;
                dd=(dd+d)%n;
            }
            else if(vis[dd]==2)
            {
                break;
            }
            if(vis[rr]==0)
            {
                vis[rr]=2;
                rr=(rr+r)%n;
            }
            else if(vis[rr]==1)
            {
                break;
            }
            t++;
        }
        printf("%d\n",t);
    }
}
