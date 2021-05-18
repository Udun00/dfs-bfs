/*
题目：https://vjudge.net/contest/438445#problem/D
思路：利用map标记字符串是否出现，若出现则循环输出-1，一直模拟出现为止
*/
//代码实现
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int o=1;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        char a[110],b[110],s[210],c[210];
        map <string,int> q;
        q.clear();
        scanf("%s",a);
        scanf("%s",b);
        scanf("%s",c);
        int len=strlen(a);
        int ans=0;
        int flag=0;
        while(1)
        {
            ans++;
            int sum=0;
            for(int i=0; i<len; i++)
            {
                s[sum++]=b[i];
                s[sum++]=a[i];
            }
            s[sum]='\0';
            //printf("%s\n%s\n",s,c);
            if(strcmp(s,c)==0)
            {
                break;
            }
            if(q[s]==1)
            {
                flag=1;
                break;
            }
            else q[s]=1;
            for(int i=0; i<len; i++)a[i]=s[i];
            for(int i=len,j=0; i<sum; i++,j++)b[j]=s[i];
            a[len]='\0';
            b[len]='\0';
            //printf("%s\n%s\n",a,b);
        }
        printf("%d ",o++);
        if(flag==1)printf("-1\n");
        else printf("%d\n",ans);
    }
}
