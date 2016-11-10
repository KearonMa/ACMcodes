#include <bits/stdc++.h>
using namespace std;
int dp[25][200];
int main()
{
    memset(dp,0,sizeof(dp));
    dp[2][0]=1;
    dp[2][1]=1;
    for(int i=3;i<=20;i++)
    {
        dp[i][0]=1;
        for(int j=0;j<i;j++)
        {
            for(int k=0;k<i*(i-1)/2;k++)
            {
                if(dp[j][k])
                {
                    dp[i][(i-j)*j+dp[j][k]*k]=1;
                }
            }
        }
    }
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<=n*(n-1)/2;i++)
        {
            if(i==0)
                printf("%d",i);
            else if(dp[n][i])
            printf(" %d",i);
        }
        printf("\n");
    }
}
