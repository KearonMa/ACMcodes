#include <iostream>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int n;
int timeList[20][20];
int ans;
int totaltime;
bool visited[20];
int zta[14][1<<14];
int zt;
int pow2[20];
int all;
void dfs(int s)
{
	if(zt==all)
	{
		int t=totaltime+timeList[s][n];
		if(t<ans)
			ans=t;
		return;
	}
	for(int i=2; i<n; i++)
	{
		if(visited[i] == 1)
			continue;
		if(totaltime+timeList[s][i] >= ans)
			continue;
		if(zta[i-2][zt+pow2[i-2]] <= totaltime+timeList[s][i])
			continue;
		visited[i]=1;
		totaltime+=timeList[s][i];
		zt+=pow2[i-2];
		zta[i-2][zt]=totaltime;
		dfs(i);
		visited[i]=0;
		totaltime-=timeList[s][i];
		zt-=pow2[i-2];
	}
}
void init()
{
	ans=inf;
	memset(visited,0,sizeof(visited));
	visited[1]=1;
	memset(zta,inf,sizeof(zta));
	zt=0;
	for(int i=0; i<14; i++)
		pow2[i]=(1<<i);
	all=0;
	for(int i=0; i<n-2; i++)
		all+=pow2[i];
	totaltime=0;
	return ;
}
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>timeList[i][j];
	init();
	dfs(1);
	cout<<ans<<endl;
}
