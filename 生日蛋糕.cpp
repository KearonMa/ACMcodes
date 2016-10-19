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
void dfs(int v,int n,int r,int h) //ʣ��n��������v����ײ�뾶������r���߶Ȳ�����h
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
    if(minV[n]>v) return ; // ʣ�µ��������С�������С
    if(h<n||r<n) return ; //ʣ�µ�h��r�Ѿ��޷�����
    if(area+minA[n]>=minArea) return ; //��ǰ���+��С����Ѿ������ܱȵ�ǰ��С���С
    if(MaxForV(n,r,h)<v) return ; //ʣ�µ�����������ҲС��ȱ�ٵ����
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
        int maxH=(N-minV[M-1])/(M*M)+1; //�ײ����߶�
        int maxR=sqrt(double(N-minV[M-1])/M)+1;  //�ײ����뾶
        area=0;
        minArea=inf;
        dfs(N,M,maxR,maxH);
        if(minArea==inf)
            printf("0\n");
        else printf("%d\n",minArea);
    }
    return 0;
}
