/*
题目：https://vjudge.net/contest/438445#problem/F
思路：每当遇见一个白色，dfs它上下左右，并把遍历过的全变成黑色，防止第二次遍历，计数
*/
//代码实现
#include<stdio.h>
int n,m;
char ma[110][110];
int s[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
void dfs(int x,int y)
{
    ma[x][y]='*';
    for(int i=0;i<8;i++)
    {
        int rx,ry;
        rx=x+s[i][0];
        ry=y+s[i][1];
        if(rx<0||ry<0||rx>=m||ry>=n)
            continue;
        if(ma[rx][ry]=='@')
        {
            dfs(rx,ry);
        }
    }
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        getchar();
        if(m==0)break;
        for(int i=0;i<m;i++)
        {
            scanf("%s",ma[i]);
            getchar();
        }
        int sum=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ma[i][j]=='@')
                {
                    dfs(i,j);
                    sum++;
                }
            }
        }
        printf("%d\n",sum);
    }
}
