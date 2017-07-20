
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m,r;
        int num,sum=0;
        scanf("%d%d",&m,&r);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&num);
            sum+=num;
        }
        if(sum+1500==r)
            printf("Correct\n");
        else
            printf("Bug\n");
    }
}
