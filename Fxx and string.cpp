#include <cstdio>
#include <cstring>
#include <cmath>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char sh[10005];
        scanf("%s",sh+1);
        int len=strlen(sh+1);
        int cou=0;
        for(int i=1;i<=len/4;i++)
        {
            for(int j=2;j<=sqrt(len);j++)
            {
                if(i*j*j>len)
                    break;
                if(sh[i]=='y'&&sh[i*j]=='r'&&sh[i*j*j]=='x')
                    cou++;
                if(sh[i]=='x'&&sh[i*j]=='r'&&sh[i*j*j]=='y')
                    cou++;
            }
        }
        printf("%d\n",cou);
    }

}

