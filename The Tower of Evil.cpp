/*
从顶部发射石头，按照碰壁反弹的运动路线问能不能击中底部的某个位置。
计算落点，飞行轨迹周期为2*(w-1)，所以直接将高度视为h=h%(2*w-2)，然后如果高度
不大于w 则落点即为高度，否则落点在2*w-h的位置。
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int h,w,s;
        int flag=0;
        scanf("%d%d%d",&h,&w,&s);
        h=h%(w*2-2);
        if(!h) h=w*2-2;
        if(h<=w) if(h==s) flag=1;
        if(h>w) if(2*w-h==s) flag=1;
        if(flag==1) printf("Yes\n");
        else printf("No\n");

    }
}
