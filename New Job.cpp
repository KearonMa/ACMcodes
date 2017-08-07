/*
有n台电脑，m根线，每台电脑只能连一根线，只有互相连线的电脑才能传输文件
每次传输一小时，问把文件从一台电脑复制到所有电脑最少需要多少时间。
在数据线够用的情况下，可以采取1台复制成2台，2台复制成4台的方式倍增每次复制的
数量，模拟这个过程计算出倍增复制的次数。当有文件的电脑达到m台之后，每次只能复
制文件到m台电脑，所以剩下的电脑数除以m向上取整即为还需要复制的次数，加上前面
得到的倍增复制次数即为答案。
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m,ans=0,c=1;
        cin>>n>>m;
        while(n>0)
        {
            if(c<m)
            {
                n-=c;
                c*=2;
                ans++;
            }
            else
            {
                ans+=(n/m);
                if(n%m) ans++;
                break;
            }
        }
        cout<<ans<<endl;
    }
}
