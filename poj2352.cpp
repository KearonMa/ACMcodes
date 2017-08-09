//树状数组
#include <cstdio>
const int maxn=32000+10;
int t[maxn],level[maxn];
int add(int x)
{
    while(x < maxn)
    {
        t[x] += 1;
        x += x&-x;
    }
}
int query(int x)
{
    int sum=0;
    while(x > 0)
    {
        sum += t[x];
        x -= x&-x;
    }
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        level[query(a+1)]++;
        add(a+1);
    }
    for(int i=0; i < n;i++)
        printf("%d\n",level[i]);
}
