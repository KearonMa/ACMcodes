#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a1,b1,c1,a2,b2,c2;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2);
        if(a1>a2)
        {
            printf("Player2\n");
        }
        else if(a1<a2)
        {
            printf("Player1\n");
        }
        else if(a1==a2)
        {
            if(b1>b2)
            {
                printf("Player2\n");
            }
            else if(b1<b2)
            {
                printf("Player1\n");
            }
            else if(b1==b2)
            {
                if(c1>c2)
                {
                    printf("Player2\n");
                }
                else if(c1<c2)
                {
                    printf("Player1\n");
                }
                else printf("Tie\n");
            }
        }

    }
}
