/*
证书可以每次批量买a个，现在需要x个，问至少要买多少个。
把所有a排序，然后对于每个x二分搜索不小于x的最小的a，然后输出即可。
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,a[maxn],m,x;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(a[mid]<x)
                l=mid+1;
            else
                r=mid-1;
        }
        if(a[l]>=x)
            cout<<a[l]<<endl;
        else
            cout<<"Dr. Samer cannot take any offer :(."<<endl;
    }
}
