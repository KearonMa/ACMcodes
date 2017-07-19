#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
#define EXP 1e-8
#define N   10007
#define M   1000007
#define mod 1000000007
#define INF 1e18
#define LL  long long
int f[N];
bool a[N][11];
char s[N];
int main()
{
    int t,n,m,r,x,y,z,w,i,j,k,l,ans,now,tmp,inf,cnt0,cnt1;
    scanf("%d",&n);
    scanf(" %s",s);
    memset(f,0,sizeof(f));
    memset(a,true,sizeof(a));
    f[0]=1;
    for(i=1;i<=n;i++)
    {
        x=s[i-1]-'0';
        for(j=max(0,i-11);j<i;j++)if(a[j][10])
        {
            if(!a[j][x])a[j][10]=false;
            else
            {
                a[j][x]=false;
                (f[i]+=f[j])%=mod;
            }
        }
    }
    printf("%d\n",f[n]);
    return 0;
}
