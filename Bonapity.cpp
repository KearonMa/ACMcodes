#include <cstdio>
#include <cstring>
int n;
char str1[110],str2[110];
void b(char s[])
{
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
            s[i]+=32;
        if(s[i]=='p') s[i]=123;
        if(s[i]=='b') s[i]=123;
        if(s[i]=='e') s[i]=124;
        if(s[i]=='i') s[i]=124;
    }
}
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%s",str1,str2);
        b(str1);
        b(str2);
        if(strcmp(str1,str2))
            printf("No\n");
        else printf("Yes\n");
    }
}
