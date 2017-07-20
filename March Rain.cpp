/*
屋顶有n个洞，用k块板子覆盖所有洞，问最长的一块板子至少是多长。
二分长度，贪心的方式尝试覆盖，把每一块板子都放在刚好能覆盖最左边的洞的最右位置
从而判断某个长度的k块板子能否覆盖所有洞。
*/
#include <bits/stdc++.h>
using namespace std;
int d[100010];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&d[i]);
        int l=0;
        int r=d[n-1]/m+1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int x=d[0];
            int cnt=1;
            for(int i=1;i<n;i++)
            {
                if(d[i]>=x+mid)
                {
                    x=d[i];
                    cnt++;
                }
            }
            if(cnt>m)
                l=mid+1;
            else
                r=mid-1;
        }
        printf("%d\n",r+1);
    }
}
