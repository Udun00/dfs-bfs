/*
题目：https://vjudge.net/contest/438445#problem/Q
思路：从最下面一层开始往上dfs，遍历每一种情况，预处理1到i的最小体积和最小面积
剪枝：已经搜过的体积加最小体积不能超过n，已经搜过的面积及积加最小面积不能超过mini，已经搜过的面积及积加是剩余体积侧面积不能超过mini
*/
//代码实现
#include<stdio.h>
#include<math.h>
int minv[30],mins[30];//1到i层的最小体积和最小面积
int mini=0x3f3f3f3f;
int n,m;
int sum=0;
void dfs(int deep,int v,int s,int h,int r)//当前层数,当前所用体积,当前所用面积,当前层半径和高度
{
    if(deep==0)
    {
        if(v==n&&s<mini)
        {
            mini=s;
        }
        return ;
    }
    //已经搜过的体积加最小体积不能超过n
    //已经搜过的面积及积加最小面积不能超过mini
    //已经搜过的面积及积加是剩余体积侧面积不能超过mini
    if(v+minv[deep-1]>n||s+mins[deep-1]>mini||s+(n-v)/r*2>=mini)
    {
        return ;
    }
    for(int i=r-1;i>=deep;i--)
    {
        if(deep==m)
        {
            s=i*i;
        }
        int h1,h2;
        h1=(n-v-minv[deep-1])/(i*i);//实际上第deep层最大的高度
        h2=(h-1)>h1?h1:(h-1);//实际上最大高度与理论上最大高度取小
        for(int j=h2;j>=deep;j--)
        {
            dfs(deep-1,v+i*i*j,s+2*i*j,j,i);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    minv[0]=0;
    mins[0]=0;
    for(int i=1;i<=m;i++)
    {
        minv[i]=minv[i-1]+i*i*i;
        mins[i]=mins[i-1]+i*i*2;
    }
    dfs(m,0,0,n,(int)sqrt((double)n));
    if(mini==0x3f3f3f3f)
    {
        printf("0");
    }
    else printf("%d",mini);
}
