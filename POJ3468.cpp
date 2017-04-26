#include <iostream>
#include <cstdio>
using namespace std;
struct cnode
{
    int l,r;
    cnode *pl,*pr;
    long long nsum;
    long long lnc;
    int mid()
    {
        return (l+r)/2;
    }
};
cnode t[200010];
int ncount=0;
void build(cnode *proot,int l,int r)
{
    proot->l=l;
    proot->r=r;
    proot->nsum=0;
    proot->lnc=0;
    if(l==r) return;
    ncount++;
    proot->pl=t+ncount;
    ncount++;
    proot->pr=t+ncount;
    build(proot->pl,l,(l+r)/2);
    build(proot->pr,(l+r)/2+1,r);
}
void insert(cnode *proot,int i,int v)
{
    proot->nsum+=v;
    if(proot->l==i&&proot->r==i)
        return;
    if(i<=proot->mid())
        insert(proot->pl,i,v);
    else
        insert(proot->pr,i,v);
}
void add(cnode *proot,int a,int b,long long c)
{
    if(proot->l==a&&proot->r==b)
    {
        proot->lnc+=c;
        return;
    }
    proot->nsum+=c*(b-a+1);
    if(b<=proot->mid())
        add(proot->pl,a,b,c);
    else if(a>=proot->mid()+1)
        add(proot->pr,a,b,c);
    else
    {
        add(proot->pl,a,proot->mid(),c);
        add(proot->pr,proot->mid()+1,b,c);
    }
}
long long query(cnode *proot,int a,int b)
{
    if(proot->l==a&&proot->r==b)
    {
        return proot->nsum+(b-a+1)*proot->lnc;
    }
    proot->nsum+=(proot->r-proot->l+1)*proot->lnc;
    add(proot->pl,proot->l,proot->mid(),proot->lnc);
    add(proot->pr,proot->mid()+1,proot->r,proot->lnc);
    proot->lnc=0;
    if(b<=proot->mid())
        return query(proot->pl,a,b);
    else if(a>=proot->mid()+1)
        return query(proot->pr,a,b);
    else
        return query(proot->pl,a,proot->mid())+query(proot->pr,proot->mid()+1,b);
}


int main()
{
    int n,q,a,b,c;
    scanf("%d%d",&n,&q);
    build(t,1,n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        insert(t,i,a);
    }
    char str[10];
    for(int i=0;i<q;i++)
    {
        scanf("%s",str);
        if(str[0]=='C')
        {
            scanf("%d%d%d",&a,&b,&c);
            add(t,a,b,c);
        }
        else
        {
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(t,a,b));
        }
    }
}
