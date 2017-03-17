#include <bits/stdc++.h>
using namespace std;
int zop[1005]; //ZeroOnePack
int c[1005];
int w[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,v;
        cin>>n>>v;
        for(int i=0;i<n;i++)
            cin>>w[i];
        for(int i=0;i<n;i++)
            cin>>c[i];
        memset(zop,0,sizeof(zop));
        for(int i=0;i<n;i++)
            for(int j=v;j>=c[i];j--)
                zop[j]=max(zop[j],zop[j-c[i]]+w[i]);
        int maxN=0;
        for(int i=1;i<=v;i++)
            if(maxN<zop[i])
                maxN=zop[i];
        cout<<maxN<<endl;
    }
}

