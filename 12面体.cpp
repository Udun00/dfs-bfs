/*
题目：https://vjudge.net/contest/438445#problem/J
思路：用一个路径数组记录路径，到终点时输出路径，并且也要用标记数组标记那些点走过，还要回溯
注意：要按字典序从小到大输出，直接在dfs时从小的开始dfs
*/
//代码实现
#include<stdio.h>
#include<string.h>
int ans=1;
int load[30],m[30][30]={0},vis[30];
int cnt=0;
void dfs(int x,int e)
{
    vis[x]=1;
    load[cnt++]=x;
    int i,j;
    for(i=0;i<3;i++)
    {
        int t;
        t=m[x][i];
        if(t==e&&cnt==20)
        {
            printf("%d:  ",ans++);
            for(j=0;j<20;j++)
            {
                printf("%d ",load[j]);
            }
            printf("%d\n",e);
        }
        if(vis[t]==0)
        {
            dfs(t,e);
        }
    }
    vis[x]=0;
    cnt--;
}
int main()
{
    int i;
    for(i=1;i<=20;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        m[i][0]=x;
        m[i][1]=y;
        m[i][2]=z;
    }
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        if(m==0)break;
        memset(vis,0,sizeof(vis));
        dfs(m,m);
    }
}
