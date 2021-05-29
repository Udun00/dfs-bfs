/*
题目：https://vjudge.net/contest/438445#problem/P
思路：题目要求下一个题目难度必须大于等于上一个题目，要求找出能做的最大题目数，一直深搜，题目数到所有题目数返回
注意：不一定没个题目都会做到，所以更新最大题目数应放在外面
*/
//代码实现
#include<stdio.h>
int t[50][50];
int vis[20];
int n;
int ma = 0;
void dfs(int i, int cnt, int last)
{
    ma = ma > cnt ? ma : cnt;
    if (cnt == n)
    {

        return;
    }
    for (int j = 1; j < n; j++)
    {
        if (vis[j] == 0 && t[i][j] >= last)
        {
           // printf("%d ", j);
            vis[j] = 1;
            dfs(j, cnt + 1, t[i][j]);
            vis[j] = 0;
        }
    }
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &t[i][j]);
            }
        }
        for (int i = 0; i < n; i++)vis[i] = 0;
        vis[0] = 1;
        ma = 0;
        dfs(0, 1, 0);
        printf("%d\n", ma);
    }
}
