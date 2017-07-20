//模拟题
#include <bits/stdc++.h>
using namespace std;
char ma[250][250];
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(ma,'.',sizeof(ma));
        int x,y,m;
        scanf("%d%d%d",&x,&y,&m);
        int x1,x2,y1,y2;
        char c;
        for(int t=0;t<m;t++)
        {
            scanf("%d %d %d %d %c",&x1,&y1,&x2,&y2,&c);
            for(int i=x1;i<=x2;i++)
                for(int j=y1;j<=y2;j++)
                ma[i][j]=c;
        }
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
                printf("%c",ma[i][j]);
            printf("\n");
        }
    }
}
