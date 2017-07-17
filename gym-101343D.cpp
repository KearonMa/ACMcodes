///水题
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        char s[110];
        while(n--)
        {
            scanf("%s",s);
            int len=strlen(s);
            int flag[3]={0};
            for(int i=0;i<len;i++)
            {
                if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
                    flag[0]++;
                if(s[i]>='0'&&s[i]<='9')
                    flag[1]++;
                if(s[i]=='@'||s[i]=='?'||s[i]=='!')
                    flag[2]++;
            }
            if(flag[0]<4)
                printf("The last character must be a letter.\n");
            else if(flag[1]<4)
                printf("The last character must be a digit.\n");
            else if(flag[2]<2)
                printf("The last character must be a symbol.\n");
            else
                printf("The last character can be any type.\n");


        }
    }
}
