/*
寻找x使得目标函数的值最小。
先统计字符串每个字母的出现次数，然后暴力穷举所有可能的x
每个都计算一次目标函数，取最小的即可。
*/
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
string s;
int scnt[30];
int main()
{
    cin>>s;
    int maxn=0;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        scnt[s[i]-97]++;
        if(maxn<scnt[s[i]-97])
            maxn=scnt[s[i]-97];
    }
    int minn=inf;
    int ans=2;
    for(int i=2;i<=maxn;i++)
    {
        long long  t=0;
        for(int j=0;j<26;j++)
            t+=(scnt[j]%i)*(long long )scnt[j];
        if(minn>t)
        {
            minn=t;
            ans=i;
        }
    }
    cout<<ans<<endl;
}
