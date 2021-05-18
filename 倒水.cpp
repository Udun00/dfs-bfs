/*
题目：https://vjudge.net/contest/438445#problem/E
思路：一共有6中操作,用bfs记录每种操作
注意：要减枝，不然内存不够，定义一个book数组记录状态,重复状态不加入队列
*/
//代码实现
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int tp = 0, ed = 0;
int book[110][110] = { 0 };
typedef struct node
{
    int a, b;
    int pre;//前驱
    int type;//1代表注满A,2代表注满B，3代表把A倒B，4代表把B倒A，5代表抽空A，6代表抽空B
    int step;
} node;
node Array[2000006];
void add(int x, int y, int z, int l, int h)
{
    if (book[x][y] == 1)return;
    else {
        Array[ed].a = x;
        Array[ed].b = y;
        Array[ed].pre = z;
        Array[ed].type = l;
        Array[ed].step = h;
        ed++;
        book[x][y] = 1;
    }
}
void dfs(int h)
{
    if (h == -1)
        return;
    dfs(Array[h].pre);
    node k = Array[h];
    if (k.type == 1)printf("FILL(1)\n");
    else if (k.type == 2)printf("FILL(2)\n");
    else if (k.type == 3)printf("POUR(1,2)\n");
    else if (k.type == 4)printf("POUR(2,1)\n");
    else if (k.type == 5)printf("DROP(1)\n");
    else if (k.type == 6)printf("DROP(2)\n");
}
int main()
{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    Array[ed].a = 0;
    Array[ed].b = 0;
    Array[ed].pre = -1;
    Array[ed].type = 0;
    Array[ed].step = 0;
    ed++;
    int flag = -1;
    while (tp < ed)
    {
        node p = Array[tp];
        if (p.a == z || p.b == z)
        {
            flag = tp;
            break;
        }
        if (p.a != x)add(x, p.b, tp, 1, p.step + 1);
        if (p.b != y)add(p.a, y, tp, 2, p.step + 1);
        if (p.a >= (y - p.b) && p.b != y)
        {
            add(p.a + p.b - y, y, tp, 3, p.step + 1);
        }
        else if (p.a < (y - p.b))
        {
            add(0, p.a + p.b, tp, 3, p.step + 1);
        }
        if (p.b >= (x - p.a) && p.a != x)
        {
            add(x, p.b + p.a - x, tp, 4, p.step + 1);
        }
        else if (p.b < (x - p.a))
        {
            add(p.a + p.b, 0, tp, 4, p.step + 1);
        }
        if (p.a != 0)add(0, p.b, tp, 5, p.step + 1);
        if (p.b != 0)add(p.a, 0, tp, 6, p.step + 1);
        tp++;
    }
    if (flag != -1)
    {
        printf("%d\n", Array[flag].step);
        int h = flag;
        dfs(h);
    }
    else printf("impossible");
}
