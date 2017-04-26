#include <cstdio>
#include <iostream>
#include <cstring>
struct node
{
    int l,r;
    int sum;
    int mid()
    {
        return (l+r)/2;
    }
};
int num[1000005];
node t[4000005];
int n,q;
int ans=0;
void init(int root,int l,int r)
{
    t[root].l=l;
    t[root].r=r;
    t[root].sum=0;
    if(l==r) return;
    else
    {
        init(2*root+1,l,t[root].mid());
        init(2*root+2,t[root].mid()+1,r);
    }
}
void in(int root,int i,int num)
{
    t[root].sum+=num;
    if(i==t[root].l&&i==t[root].r) return;
    else if(i<=t[root].mid())
        in(2*root+1,i,num);
    else
        in(2*root+2,i,num);
}
void qu(int root,int l,int r)
{
    if(t[root].l==l&&t[root].r==r)
    {
        ans+=t[root].sum;
        return;
    }
    if(r<=t[root].mid())
    {
        qu(2*root+1,l,r);
    }
    else if(l>t[root].mid())
    {
        qu(2*root+2,l,r);
    }
    else
    {
        qu(2*root+1,l,t[root].mid());
        qu(2*root+2,t[root].mid()+1,r);
    }
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&q);
    init(0,1,n);
    memset(num,0,sizeof(num));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        num[i]=num[i]+num[i-1];
    }
    char str[15];
    int a,b;
    for(int i=0;i<q;i++)
    {
        scanf("%s",str);
        if(str[0]=='A')
        {
            scanf("%d%d",&a,&b);
            in(0,a,b);
        }
        if(str[0]=='Q')
        {
            ans=0;
            scanf("%d%d",&a,&b);
            qu(0,a,b);
            printf("%d\n",ans+num[b]-num[a-1]);
        }
    }
}

