/*
用1-9填满方格，每个数一次，相邻的数的位置也必须相邻
已经填好一些数，求填剩下数的方案数。
直接把剩下的数全排列，然后判断即可
*/
#include <bits/stdc++.h>
using namespace std;
bool v[10];
bool vis[5][5];
char ma[5][5];
int cop[5][5];
int arra[10];
int ans=0,cnt=0;
int xy[8][2]={{ -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }};
void mdfs(int x,int y,int n)
{
    if(n==9)
    {
        ans++;
        return;
    }
    for(int i=0;i<8;i++)
    {
        int dx=x+xy[i][0];
        int dy=y+xy[i][1];
        if(dx<0||dy<0||dx>=3||dy>=3)
            continue;
        if(vis[dx][dy])
            continue;
        if(fabs(cop[x][y]-cop[dx][dy])==1)
        {
            vis[dx][dy]=1;
            mdfs(dx,dy,n+1);
            vis[dx][dy]=0;
        }
    }
}
void ndfs(int n)
{
    if(n==cnt)
    {
        memset(vis,0,sizeof(vis));
        int l=0;
        int x,y;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                if(ma[i][j]==0)
                    cop[i][j]=arra[l++];
                else
                    cop[i][j]=ma[i][j];
                if(cop[i][j]==1)
                {
                    x=i;
                    y=j;
                }
            }
        vis[x][y]=1;
        mdfs(x,y,1);
        return;
    }
    for(int i=1;i<10;i++)
    {
        if(v[i]) continue;
        arra[n]=i;
        v[i]=1;
        ndfs(n+1);
        v[i]=0;
    }
}
int main()
{
    memset(v,0,sizeof(v));
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            char c;
            cin>>c;
            ma[i][j]=c-'0';
            v[ma[i][j]]=1;
            if(ma[i][j]==0)
                cnt++;
        }
        ndfs(0);
    cout<<ans<<endl;
}
