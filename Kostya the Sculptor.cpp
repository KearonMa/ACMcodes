#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct rect{
    int x,y,z,num;
}rec[maxn];
bool cmp(rect a,rect b)
{
    if(a.x==b.x&&a.y==b.y) return a.z<b.z;
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
int mySort(int &a,int &b,int &c)
{
    int t;
    if(a<b) { t=a; a=b; b=t; }
    if(b<c) { t=b; b=c; c=t; }
    if(a<b) { t=a; a=b; b=t; }
}
int main()
{
    int n,a,b,c;
    int ans1,ans2;
    int flag=0;
    int MaxR=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        mySort(a,b,c);
        rec[i].x=a;
        rec[i].y=b;
        rec[i].z=c;
        rec[i].num=i;
        if(MaxR<c) { MaxR=c; ans1=i; }
    }
    sort(rec+1,rec+1+n,cmp);
    for(int i=1;i<n;i++)
    {
        if(rec[i].x==rec[i+1].x&&rec[i].y==rec[i+1].y)
            {
                int sum=min(rec[i].z+rec[i+1].z,rec[i].y);
                if(sum>MaxR)
                {
                     MaxR=sum;
                     flag=1;
                     if(rec[i].num<rec[i+1].num) { ans1=rec[i].num; ans2=rec[i+1].num; }
                    else { ans1=rec[i+1].num; ans2=rec[i].num; }
                }
            }
    }
    if(flag)
        printf("2\n%d %d\n",ans1,ans2);
    else printf("1\n%d\n",ans1);

}
