///水题
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int m;
    int ans[110];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        scanf("%d",&m);
        if(i==j)
        {
            ans[i]=sqrt(m);
        }
    }
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    printf("\n");
}
