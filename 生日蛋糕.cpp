#include <cstdio>
#include <cmath>
#include <algorithm>
const int inf=0x3f3f3f3f;
int N,M;
int minV[25],minA[25];
int area,minArea;
using namespace std;
int MaxForV(int n,int r,int h)
{
    int v=0;
    for(int i=0;i<n;i++)
        v+=(r-i)*(r-i)*(h-i);
    return v;
}
void dfs(int v,int n,int r,int h) //剩下n层的体积是v且最底层半径不超过r，高度不超过h
{
    if(!n)
    {
        if(v) return ;
        else
        {
            minArea=min(minArea,area);
            return ;
        }
    }
    if(v<=0) return ;
    if(minV[n]>v) return ; // 剩下的体积比最小的体积还小
    if(h<n||r<n) return ; //剩下的h或r已经无法分配
    if(area+minA[n]>=minArea) return ; //当前面积+最小面积已经不可能比当前最小面积小
    if(MaxForV(n,r,h)<v) return ; //剩下的组成最大的体积也小于缺少的体积
    for(int newr=r;newr>=n;newr--) //
    {
        if(n==M)
            area=newr*newr;
        for(int newh=h;newh>=n;newh--)
        {
            area+=2*newr*newh;
            dfs(v-newr*newr*newh,n-1,newr-1,newh-1);
            area-=2*newr*newh;
        }
    }

}
int main()
{
    scanf("%d%d",&N,&M);
    minV[0]=minA[0]=0;
    for(int i=1;i<M;i++)
    {
        minV[i]=minV[i-1]+i*i*i;
        minA[i]=minA[i-1]+2*i*i;
    }
    if(N<minV[M]) printf("0\n");
    else
    {
        int maxH=(N-minV[M-1])/(M*M)+1; //底层最大高度
        int maxR=sqrt(double(N-minV[M-1])/M)+1;  //底层最大半径
        area=0;
        minArea=inf;
        dfs(N,M,maxR,maxH);
        if(minArea==inf)
            printf("0\n");
        else printf("%d\n",minArea);
    }
    return 0;
}
