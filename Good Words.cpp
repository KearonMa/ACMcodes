//模拟题
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char a[1010],b[10];
        scanf("%s%s",a,b);
        int flag=0;
        int len=strlen(a);
        for(int i=0;i<len;i++)
            if(a[i]==b[0]&&a[i+1]==b[1]&&a[i+2]==b[2]&&a[i+3]==b[3])
                flag=1;
        if(flag==1)
        {
            printf("good\n");
            continue;
        }
        for(int i=0;i<len;i++)
        {
            if(a[i]==b[0]&&a[i+1]==b[1]&&a[i+2]==b[2])
                flag=1;
            if(a[i]==b[0]&&a[i+1]==b[1]&&a[i+2]==b[3])
                flag=1;
            if(a[i]==b[0]&&a[i+1]==b[2]&&a[i+2]==b[3])
                flag=1;
            if(a[i]==b[1]&&a[i+1]==b[2]&&a[i+2]==b[3])
                flag=1;
        }
        if(flag==1)
            printf("almost good\n");
        else
            printf("none\n");
    }
}
