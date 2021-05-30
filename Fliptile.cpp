/*
题目：https://vjudge.net/contest/438445#problem/B
思路：把2~n-1行的翻转问题转换成上一行同一位置的方块的问题，即每一行的翻转把上一行全变成白色，然后判断最后一行是否全为白色
注意：第一行的翻转情况可以用二进制处理，每一个二进制代表第一行的一种翻转状态
*/
//代码实现
#include<stdio.h>
#include<string.h>
int num[20][20];
int a[20][20];
int mp[20][20];
int s[4][2]={{0,0},{0,-1},{0,1},{-1,0}};//不需要往下遍历
int n,m;
int  dfs()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int sum=mp[i][j];
            for(int k=0;k<4;k++)
            {
                int rx=i+s[k][0];
                int ry=j+s[k][1];
                sum+=num[rx][ry];
            }
            if(sum&1)//如果这个块为黑色，下一行同一位置反转是它变成白色
            {
                num[i+1][j]=1;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        int sum=mp[n][i];
        for(int j=0;j<4;j++)
        {
            int rx=n+s[j][0];
            int ry=i+s[j][1];
            sum+=num[rx][ry];
        }
        if(sum&1)return -1;//最后一行有白色退出
    }
    int h=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(num[i][j]&1)
            {
                h++;
            }
        }
    }
    return h;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&mp[i][j]);
        }
    }
    int mi=999999999;
    for(int i=0;i<(1<<n);i++)//每一个二进制数对应第一行的一种状态
    {
        memset(num,0,sizeof(num));
        for(int j=0;j<m;j++)
        {
            num[1][j+1]=(i>>j)&1;//二进制处理
        }
        int ll=dfs();
        if(ll==-1)continue ;
        if(mi>ll)//更新
        {
            mi=ll;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    a[i][j]=num[i][j];
                }
            }
        }
    }
    if(mi==999999999)
    {
        printf("IMPOSSIBLE\n");
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
}

