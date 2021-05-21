/*
题目：https://vjudge.net/contest/438445#problem/M
思路：走迷宫，有2层，和传送门，把两层都是传送门或一边是传送门一边是墙的直接堵死，在判断最小出来时间是否小于规定时间
*/
//代码实现
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
typedef struct node
{
    int x, y, z;
    int time;
} node;
int stx, sty, stz, edx, edy, edz;
int a[20][20][3];//-1代表墙，2代表传送门，1代表路
int book[20][20][3];
int s[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int main()
{
    int c;
    cin >> c;
    while (c--)
    {
        queue<node> q;
        int n, m, t;
        cin >> n >> m >> t;
        memset(book, 0, sizeof(book));
        for (int k = 1; k <= 2; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    char x;
                    cin >> x;
                    if (x == 'S')
                    {
                        stx = i, sty = j, stz = k;
                        a[i][j][k] = 1;
                    }
                    else if (x == 'P')
                    {
                        edx = i, edy = j, edz = k;
                        a[i][j][k] = 1;
                    }
                    else if (x == '.')
                    {
                        a[i][j][k] = 1;
                    }
                    else if (x == '*')
                    {
                        a[i][j][k] = -1;
                    }
                    else
                    {
                        a[i][j][k] = 2;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j][1] == 2 && a[i][j][2] == 2)
                {
                    a[i][j][1] = a[i][j][2] = -1;
                }
                else if (a[i][j][1] == 2 && a[i][j][2] == -1)
                {
                    a[i][j][1] = a[i][j][2] = -1;
                }
                else if (a[i][j][1] == -1 && a[i][j][2] == 2)
                {
                    a[i][j][1] = a[i][j][2] = -1;
                }
            }
        }
        node h;
        int flag = t+1;
        book[stx][sty][stz] = 1;
        h.x = stx, h.y = sty, h.z = stz, h.time = 0;
        q.push(h);
        while (!q.empty())
        {
            int rx, ry, rz;
            node p = q.front();
            if (p.x == edx && p.y == edy && p.z == edz)
            {
                flag = p.time;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                rx = p.x + s[i][0];
                ry = p.y + s[i][1];
                rz = p.z;
                if (rx<1 || ry<1 || rx>n || ry>m)
                    continue;
                if (a[rx][ry][rz] != -1 && book[rx][ry][rz] == 0)
                {
                    if (a[rx][ry][rz] == 2)
                    {
                        book[rx][ry][rz] = 1;
                        rz = 3 - rz;
                        if (a[rx][ry][rz] == -1)
                        {
                            continue;
                        }
                    }
                    if (book[rx][ry][rz] == 0 && a[rx][ry][rz] != -1) {
                        node yy;
                        yy.x = rx;
                        yy.y = ry;
                        yy.z = rz;
                        yy.time = p.time + 1;
                        q.push(yy);
                        book[rx][ry][rz] = 1;
                        //printf("%d %d %d %d\n", yy.x, yy.y, yy.z, yy.time);
                    }
                }
            }
            //printf("%d %d %d %d\n",p.x,p.y,p.z,p.time);
            q.pop();
        }
        if (flag<=t)printf("YES\n");
        else printf("NO\n");
    }
}
