/*
题目：https://vjudge.net/contest/438445#problem/C
思路：用dfs一直递归到，可以整除为止,如果出现重复数字则返回输出-1，dfs(x*10),dfs(x*10+1)
*/
//代码实现
#include<cstdio>
#include<queue>
using namespace std;
long long int ans,n;
int flag=0;
void dfs(long long int x,int step)
{
    if(flag==1)return ;
    if(step>19)return ;
    if(x%n==0)
    {
        flag=1;
        ans=x;
        return ;
    }
    dfs(x*10,step+1);
    dfs(x*10+1,step+1);
}
int main()
{
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)break;
        ans=0;
        flag=0;
        dfs(1,1);
        printf("%lld\n",ans);
    }
}
