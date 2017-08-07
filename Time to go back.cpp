/*
商店里有n个物品，现在要买m个物品，其中至少k个的价格不少于d，求买的方案数。
设这n个物品里有x个的价格不少于d，那么实际购买的价格不少于d的物品个数可以是不
少于k不多于x的任意整数，枚举购买的价格不少于d的物品的数量，然后用组合数计算选
择物品的方案数，最后的总和即为答案。
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
long long c[210][210];
void getc()
{
    memset(c,0,sizeof(c));
    for(int i=0;i<=200;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=c[i-1][j-1]%mod+c[i-1][j]%mod;
    }
}
int main()
{
    getc();
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k,d;
        int cost[210];
        cin>>n>>m>>k>>d;
        for(int i=0;i<n;i++)
            cin>>cost[i];
        sort(cost,cost+n);
        int g=0;
        for(;g<n;g++)
        {
            if(cost[g]>=d)
                break;
        }
        long long ans=0;
        for(int i=m;i>=k;i--)
        {
            ans=(ans+(c[n-g][i]%mod*c[g][m-i]%mod)%mod)%mod;
        }
        cout<<ans<<endl;

    }
}
