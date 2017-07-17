/*
把一个字符串分成若干段，每一段里面的字符不能重复，问有多少种分法
动态规划，定义dp 表示字符串前n个字母的分法种数，先预处理字符串，对于每个字符，
计算出以这个字符为结尾的无重复字符的一段最长的长度，第i个字符对应的长度记为f[i]
然后可以得出递推式：
dp[0]=1;
dp[i]=dp(i-j) (1<=j<=f[i])
*/
#include <bits/stdc++.h>
using namespace std;
int dp[10005];
int f[10005];
bool vis[10];
const int mod=1e9+7;
int main()
{
    string s;
    int n;
    cin>>n>>s;
    memset(dp,0,sizeof(dp));
    memset(f,0,sizeof(f));
    for(int i=0;i<n;i++)
    {
        memset(vis,0,sizeof(vis));
        int cnt=0;
        for(int j=i;j>=0;j--)
        {
            if(vis[s[j]-'0'])
                break;
            cnt++;
            vis[s[j]-'0']=1;
        }
        f[i+1]=cnt;
    }
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=1;j<=f[i];j++)
        {
            sum=(sum+dp[i-j])%mod;
        }
        dp[i]=sum;
    }
    cout<<dp[n]%mod<<endl;
}
