#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long  ans=0;
        long long n,m;
        long long c=1;
        cin>>n>>m;
        while(n>0)
        {
            if(c<m)
            {
                ans++;
                n-=c;
                c*=2;
            }
            else
            {
                c=m;
                ans+=(n/m);
                if(n%m) ans++;
                break;
            }
        }
        cout<<ans<<endl;
    }
}
