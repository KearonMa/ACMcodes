#include <cstdio>
#include <cstring>
#define MAX 60
int r,c;
int room[MAX][MAX];
int color[MAX][MAX];
int maxRoom,roomNum;
int roomArea;
void dfs(int i,int j)
{
    if(color[i][j])
        return ;
    roomArea++;
    color[i][j]=roomNum;
    if((room[i][j]&1)==0) dfs(i,j-1);
    if((room[i][j]&2)==0) dfs(i-1,j);
    if((room[i][j]&4)==0) dfs(i,j+1);
    if((room[i][j]&8)==0) dfs(i+1,j);
}
int main()
{
    scanf("%d%d",&r,&c);
    memset(color,0,sizeof(color));
    maxRoom=0; roomNum=0;
    for(int i=1; i<=r; i++)
        for(int j=1; j<=c; j++)
            scanf("%d",&room[i][j]);
    for(int i=1; i<=r; i++)
        for(int j=1; j<=c; j++)
            if(!color[i][j])
            {
                roomNum++;
                roomArea=0;
                dfs(i,j);
                if(maxRoom<roomArea)
                    maxRoom=roomArea;
            }
    printf("%d\n%d\n",roomNum,maxRoom);
}
