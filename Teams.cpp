/*
n个学校，第i个有 个参赛者，一个队伍k个人，每个队伍所有人必须来自同一学校，
求k使得队伍数量m最少。
因为k必须整除每个学校的参赛者数量
直接用gcd
*/
#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
     return b ? gcd(b,a%b) : a;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m;
        int num[1010];
        scanf("%d",&m);
        for(int i=0;i<m;i++)
            scanf("%d",&num[i]);
        if(m==1)
        {
            printf("%d 1\n",num[0]);
            continue;
        }
        int b=gcd(num[0],num[1]);
        for(int i=2;i<m;i++)
            b=gcd(b,num[i]);
        int sum=0;
        for(int i=0;i<m;i++)
            sum=sum+num[i]/b;
        printf("%d %d\n",b,sum);
    }
}
