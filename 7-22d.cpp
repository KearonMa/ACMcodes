#include <bits/stdc++.h>
const int mod=1000000007;
using namespace std;
//long long  com(long long n,long long r)
//{
//    if(n-r>r) r=n-r;
//    long long  i,j,s=1;
//    for(i=0,j=1;i<r;++i)
//    {
//        s*=(n-i);
//        for(;j<=r&&s%j==0;j++)
//            s/=j;
//    }
//    return s;
//}
long long c[210][210];
int main()
{

    int t;
    cin>>t;
    memset(c,0,sizeof(c));
    for(int i=0;i<=200;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=c[i-1][j-1]%mod+c[i-1][j]%mod;
    }
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
            //ans=ans+com(n-g,i)%mod*com(g,m-i)%mod;
            ans=(ans+(c[n-g][i]%mod*c[g][m-i]%mod)%mod)%mod;
        }
        cout<<ans<<endl;

    }
}
