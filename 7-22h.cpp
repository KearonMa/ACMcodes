#include <bits/stdc++.h>
using namespace std;
long long dp[255][255];
int main()
{
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=250; i++)
        for(int j=1; j<=250; j++)
        {
            if(i==1||j==1) dp[i][j]=1;
            else if(i>j) dp[i][j]=dp[i-j][j]+dp[i][j-1];
            else if(i==j) dp[i][j]=dp[i][j-1]+1;
            else if(i<j) dp[i][j]=dp[i][i];
        }
    int n;
    while(cin>>n&&n)
    {
        long long ans=0;
        if(n%2)
        {
            for(int i=1;i<=n; i+=2)
                ans+=dp[(n-i)/2][i];
        }
        else
        {
            for(int i=2; i<=n; i+=2)
                ans+=dp[(n-i)/2][i];
            ans+=dp[n/2][n/2];
        }
        cout<<++ans<<endl;
    }
}
