#include <cstdio>
#include <iostream>
const int inf=0x3f3f3f3f;
int maxn,minn;
struct node
{
    int l,r,mid;
    int maxn,minn;
};
node t[800000];
void init(int root,int l,int r)
{
    t[root].l=l;
    t[root].r=r;
    t[root].mid=(l+r)/2;
    t[root].minn=inf;
    t[root].maxn=-inf;
    if(l!=r)
    {
        init(2*root+1,l,(l+r)/2);
        init(2*root+2,(l+r)/2+1,r);
    }
}
void insert(int root,int x,int num)
{
    if(t[root].l==t[root].r)
    {
        t[root].minn=t[root].maxn=num;
        return;
    }
    t[root].minn=std::min(t[root].minn,num);
    t[root].maxn=std::max(t[root].maxn,num);
    if(x<=t[root].mid)
        insert(2*root+1,x,num);
    else
        insert(2*root+2,x,num);
}
void query(int root,int l,int r)
{
    if(t[root].minn>=minn&&t[root].maxn<=maxn)
        return;
    if(t[root].l==l&&t[root].r==r)
    {
        minn=std::min(t[root].minn,minn);
        maxn=std::max(t[root].maxn,maxn);
        return;
    }
    if(r<=t[root].mid)
        query(2*root+1,l,r);
    else if(l>t[root].mid)
        query(2*root+2,l,r);
    else
    {
        query(2*root+1,l,t[root].mid);
        query(2*root+2,t[root].mid+1,r);
    }
}
int main()
{
    int n,q,h;
    scanf("%d%d",&n,&q);
    init(0,1,n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&h);
        insert(0,i,h);
    }
    int l,r;
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&l,&r);
        maxn=-inf;
        minn=inf;
        query(0,l,r);
        printf("%d\n",maxn-minn);
    }
    return 0;
}
