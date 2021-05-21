/*
题目：https://vjudge.net/contest/438445#problem/T
思路：每一位都可以有三种变化，bfs列举
*/
//代码实现
#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;
int b[100010];
typedef struct node
{
    int data;
    int step;
} node;
int y(int a,int b,int c,int d)
{
    return a*1000+b*100+c*10+d*1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(b,0,sizeof(b));
        int n,m;
        cin>>n>>m;
        getchar();
        getchar();
        queue<node>q;
        node h;
        h.data=n;
        h.step=0;
        b[n]=1;
        q.push(h);
        int flag=0;
        while(!q.empty())
        {
            node p=q.front();
            if(p.data==m)
            {
                flag=p.step;
                break;
            }
            int a[5];
            a[1]=p.data/1000;
            a[2]=(p.data/100)%10;
            a[3]=(p.data/10)%10;
            a[4]=p.data%10;
            for(int i=1; i<=4; i++)
            {
                int t[5]= {0};
                for(int j=1; j<=4; j++)t[j]=a[j];
                int x;
                if(t[i]+1>9)t[i]=1;
                else t[i]++;
                x=y(t[1],t[2],t[3],t[4]);
                if(b[x]==0)
                {
                    b[x]=1;
                    node yy;
                    yy.data=x;
                    yy.step=p.step+1;
                   // printf("%d %d\n",yy.data,yy.step);
                    q.push(yy);
                }
            }
            for(int i=1; i<=4; i++)
            {
                int t[5]= {0};
                for(int j=1; j<=4; j++)t[j]=a[j];
                int x;
                if(t[i]-1<1)t[i]=9;
                else t[i]--;
                x=y(t[1],t[2],t[3],t[4]);
                if(b[x]==0)
                {
                    b[x]=1;
                    node yy;
                    yy.data=x;
                    yy.step=p.step+1;
                   // printf("%d %d\n",yy.data,yy.step);
                    q.push(yy);
                }
            }
            for(int i=1; i<=3; i++)
            {
                int t[5]= {0};
                for(int j=1; j<=4; j++)t[j]=a[j];
                int temp;
                temp=t[i];
                t[i]=t[i+1];
                t[i+1]=temp;
                int x=y(t[1],t[2],t[3],t[4]);
                if(b[x]==0)
                {
                    b[x]=1;
                    node yy;
                    yy.data=x;
                    yy.step=p.step+1;
                  //  printf("%d %d\n",yy.data,yy.step);
                    q.push(yy);
                }
            }
            q.pop();
        }
        cout<<flag<<endl;
    }
}
