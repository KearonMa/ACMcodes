#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char str[100004];
int main()
{
    int N,i;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%s",str);
        int len = strlen(str);
        long long ans = 0,num = 0;
        for(i = 0; i < len; i++)
        {
            if(str[i]=='q')
            {
                num++;
            }
            else
            {
                ans = ans + (num*(num+1))/2;
                num = 0;
            }
        }
        ans = ans + (num*(num+1))/2;
        printf("%lld\n",ans);
    }
    return 0;
}
