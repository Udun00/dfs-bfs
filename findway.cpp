/*
题目：https://vjudge.net/contest/438445#problem/G
思路：使用两次广搜，把到两次的结果加起来，取最小
*/
//代码实现
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
typedef struct
{
    int x,y;
} node;
int dis1[210][210],dis2[210][210];
int vis[210][210];
int s[4][2]= {{0,1},{0,-1},{1,0},{-1,0}};
int x1,x2,z1,z2;
int n,m;
char map_x[210][210];
queue<node> q;
void bfs(int x,int y)
{
    node p;
    p.x=x;
    p.y=y;
    vis[x][y]=1;
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        int rx,ry;
        for(int i=0; i<4; i++)
        {
            rx=p.x+s[i][0];
            ry=p.y+s[i][1];
            if(rx<1||ry<1||rx>n||ry>m)
                continue;
            if(map_x[rx][ry]!='#'&&vis[rx][ry]==0)
            {
                vis[rx][ry]=1;
                node yy;
                yy.x=rx;
                yy.y=ry;
                q.push(yy);
                dis1[rx][ry]=dis1[p.x][p.y]+1;
                dis2[rx][ry]+=dis1[rx][ry];
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(dis1,0,sizeof(dis1));
        memset(dis2,0,sizeof(dis2));
        memset(vis,0,sizeof(vis));
        getchar();
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%c",&map_x[i][j]);
                //printf("%c",map_x[i][j]);
                if(map_x[i][j]=='Y')
                {
                    x1=i,z1=j;
                }
                if(map_x[i][j]=='M')
                {
                    x2=i,z2=j;
                }
            }
            getchar();
        }
        bfs(x1,z1);
        memset(dis1,0,sizeof(dis1));
        memset(vis,0,sizeof(vis));
        while(!q.empty())
        {
            q.pop();
        }
        bfs(x2,z2);
        int mi=inf;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(map_x[i][j]=='@'&&dis2[i][j])
                {
                    mi=min(dis2[i][j],mi);
                }
            }
        }
        printf("%d\n",mi*11);
        //dfs1(x1,y1);
        //dfs2(x2,y2);
    }
}
