/*
对于数组的每个元素，找到它右边的第一个比它大的元素
根据数组元素内容建立索引，有序记录a的每个值的所有出现的位置，然后对于每个a，
遍历所有大于a的可能的值，每个值用二分搜索找到当前位置右边的最小的出现位置，
(直接遍历会超时)
然后这些位置中取最小值即为结果所在的位置。
*/
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n;
int a[100005];
int f[55][100005];
int len[55];
int main()
{
    cin>>n;
    memset(len,0,sizeof(len));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]][len[a[i]]]=i;
        len[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        int num=a[i];
        int wz=inf;
        for(int j=num+1;j<=50;j++)
        {
//            for(int l=0;k<len[j];l++)
//            {
//                if(f[j][l]>i&&f[j][l]<wz)
//                    wz=f[j][l];
//            }
            int l=0,r=len[j]-1;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(f[j][mid]>i)
                    r=mid;
                else
                    l=mid+1;
            }
            if(f[j][r]>i)
                if(wz>f[j][r])
                    wz=f[j][r];
        }
        if(wz==inf)
            cout<<-1<<' ';
        else
            cout<<a[wz]<<' ';
    }
    cout<<endl;
}
