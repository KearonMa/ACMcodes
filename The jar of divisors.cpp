/*
1到n的n个数，两个人轮流去掉一个数字及这个数字的所有因数，最后去完的人赢，求谁赢。
n为1则后手赢，否则先手赢。
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n>1)
            cout<<"Alice"<<endl;
        else
            cout<<"Bob"<<endl;;
    }
}
