/*
题目：https://vjudge.net/contest/438445#problem/A
思路：这是一个三维的走迷宫问题，用bfs遍历每个方向（上下左右前后）
注意：用dfs会超时,且不知到什么时候截至有最小值
*/
//代码实现
#include<cstdio>
#include<queue>
using namespace std;
typedef struct node
{
    int x,y,z;
    int sum;
}node;
char m[40][40][40];
int book[40][40][40];
int ok;
int l, r, c;
int stx , sty , stz , endx , endy , endz ;
int s[50][4] = { {0,0,1}, {0,1,0},{1,0,0},{0,0,-1},{0,-1,0},{-1,0,0} };//上下左右前后走
int main()
{
    while (scanf("%d%d%d", &l, &r, &c) != EOF)
    {
        ok = 0;
        char u, o, y;
        y=getchar();
        int i,j,k;
        stx = 0, sty = 0, stz = 0, endx = 0, endy = 0, endz = 0;
        if (l == 0 && r == 0 && c == 0)break;
        for ( i = 1; i <= l; i++)
        {
            for ( j = 1; j <= r; j++)
            {
                for ( k = 1; k <= c; k++)
                {
                    book[i][j][k]=0;
                    scanf("%c", &m[i][j][k]);
                    if (m[i][j][k] == 'S')
                    {
                        stz = i;
                        stx = j;
                        sty = k;
                    }
                    else if (m[i][j][k] == 'E')
                    {
                        endz = i;
                        endx = j;
                        endy = k;
                    }
                }
                 o=getchar();
            }
             u = getchar();
        }
        queue<node> q;
        node a;
        a.x=stx,a.y=sty,a.z=stz,a.sum=0;
        q.push(a);
        int ans=0;
        while(!q.empty())
        {
            node p=q.front();
            q.pop();
            if(p.x==endx&&p.y==endy&&p.z==endz)
            {
                ans=p.sum;
                ok=1;
                break;
            }
            for(int i=0;i<6;i++)
            {
                int rx,ry,rz;
                rx=p.x+s[i][0];
                ry=p.y+s[i][1];
                rz=p.z+s[i][2];
                if(rx<1||ry<1||rz<1||rx>r||ry>c||rz>l)
                    continue;
                if(m[rz][rx][ry]!='#'&&book[rz][rx][ry]==0)
                {
                    node hk;
                    hk.x=rx;
                    hk.y=ry;
                    hk.z=rz;
                    hk.sum=p.sum+1;
                    q.push(hk);
                    book[rz][rx][ry]=1;
                }
            }
        }
        if (ok == 1)printf("Escaped in %d minute(s).\n",ans);
        else printf("Trapped!\n");
    }
}
