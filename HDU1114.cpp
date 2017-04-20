#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int dp[10010];
int p[510];
int w[510];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int e,f,n,cw;
        cin>>e>>f;
        cw=f-e;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>p[i]>>w[i];
        memset(dp,inf,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<n;i++)
            for(int j=w[i];j<=cw;j++)
            dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
        if(dp[cw]==inf)
            cout<<"This is impossible."<<endl;
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[cw]<<"."<<endl;
    }
}
