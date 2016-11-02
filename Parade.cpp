#include <bits/stdc++.h>
int L,R;
int main()
{
    int n;
    scanf("%d",&n);
    L=R=0;
    int l[100005],r[100005];
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        L+=l[i];
        R+=r[i];
    }
    int maxn=abs(L-R);
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        L-=l[i];
        L+=r[i];
        R-=r[i];
        R+=l[i];
        if(abs(L-R)>maxn)
        {
            maxn=abs(L-R);
            ans=i;
        }
        L+=l[i];
        L-=r[i];
        R+=r[i];
        R-=l[i];
    }
    printf("%d\n",ans);

}
