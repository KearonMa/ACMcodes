/*
a or c = b，已知a和b，求c可能有多少种值。
对比二进制每一位，如果A为1，B为0，则不可能，如果A为1，B为1，则C的这一位可以
是0也可以是1，所以结果乘以2，其他情况C的这一位必须和B一致，所以结果不变。
*/
#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int main()
{
    char a[110],b[110];
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int len;
        scanf("%d%s%s",&len,a,b);
        int ans=1;
        for(int i=0; i<len; i++)
        {
            if(a[i]=='1'&&b[i]=='0')
            {
                printf("IMPOSSIBLE\n");
                ans=0;
                break;
            }
            if(a[i]=='1'&&b[i]=='1') ans=(ans*2)%mod;
        }
        ans=ans%mod;
        if(ans!=0)
        printf("%d\n",ans);

    }
}
