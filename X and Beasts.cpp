/*
n个商店，每个商店的数值是ai，能提升的能力值为ai的二进制形式的结尾0的个数
购买序列的ai必须升序，问顺序访问商店最大提升能力值为多少
动态规划，定义dp[n]为以购买第n个商店的升级为结尾的购买方案的提升最大值
所以dp[0]=0;
dp[i]=max(dp[i],dp[j]+k[i]);
*/
#include <bits/stdc++.h>
using namespace std;
int pow2[32];
int dp[110];
void init()
{
    pow2[0]=1;
    for(int i=1;i<20;i++)
        pow2[i]=pow2[i-1]*2;
}
int main()
{
    int n;
    init();
    scanf("%d",&n);
    while(n--)
    {
        memset(dp,0,sizeof(dp));
        int m,t[110],k[110];
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&t[i]);

            for(int j=17;j>=0;j--)
                if(t[i]%pow2[j]==0)
                {
                    k[i]=j;
                    dp[i]=j;
                    break;
                }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<i;j++)
                if(t[i]>t[j])
                dp[i]=max(dp[i],dp[j]+k[i]);
        }
        int ans=0;
        for(int i=0;i<m;i++)
            if(ans<dp[i]) ans=dp[i];
        printf("%d\n",ans);
    }
}
