/*
题目：https://vjudge.net/contest/438445#problem/L
思路：从序列中最大序列长度开始枚举，直到找到一种满足的序列，在一个位置加4种dna字符，如果全都满足就退出
*/
//代码实现
#include<stdio.h>
#include<string.h>
int deep;
int ans;
int dna[4]={'A','C','T','G'};
char a[10][10];
int len[10];
int n;
void dfs(int x,int pre[10])//pre[j]代表，上一个长度dna序列满足最长的长度，deep为最大规定长度
{
    if(x>deep)return ;
    int ma=0;
    for(int i=1;i<=n;i++)
    {
       // printf("%d %d\n",len[i],pre[i]);
        ma=ma>(len[i]-pre[i])?ma:(len[i]-pre[i]);//不满足长度取最大
    }
    //printf("%d\n",ma);
    if(ma==0)//找到答案
    {
        ans=x;
        return ;
    }
    if(ma+x>deep)return ;
    for(int i=0;i<4;i++)
    {
        int p[10]={0},flag=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j][pre[j]]==dna[i])//添加dna字符
            {
                p[j]=pre[j]+1;
                flag=1;
            }
            else
            {
                p[j]=pre[j];
            }
        }
        if(flag)//如果有贡献就搜，不然不搜
        {
            dfs(x+1,p);
        }
        if(ans>0)//找到答案
            break;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();
        ans=0;
        deep=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",a[i]);
            len[i]=strlen(a[i]);
            deep=deep>len[i]?deep:len[i];
        }
        int y[10]={0};
        //for(int i=1;i<=n;i++){
        //    printf("%d ",y[i]);
       // }
        while(1)
        {
            dfs(0,y);
            if(ans>0)break;
            deep++;
        }
        printf("%d\n",ans);
    }
}
