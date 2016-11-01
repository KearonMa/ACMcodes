#include <cstdio>
#include <cstring>
int main()
{
    char sh[1000];
    while(~scanf("%s",sh))
    {
        int len=strlen(sh);
        int jump=0;
        int maxn=0;
        for(int i=0;i<len;++i)
        {
            jump++;
            if(sh[i]=='A'||sh[i]=='E'||sh[i]=='I'||sh[i]=='O'||sh[i]=='U'||sh[i]=='Y')
            {
                if(maxn<jump)
                        maxn=jump;
                jump=0;
            }
        }
        if(maxn<jump+1) maxn=jump+1;
        printf("%d\n",maxn);
    }
}
