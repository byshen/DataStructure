#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("1.txt");

int head[100001]={0},Q[100001] = {0},mark[100001] = {0},begin = 1, tail = 0;
int flag[100001] = {0},father[100001];

bool enQueue(int i)
{
    if (mark[i]) return false;
    mark[i] = 1;
    ++tail;
    Q[tail] = i;
    --flag[i];
    return true;
}


struct{
int a, b, next;} e[100001];

void topsort(int n, int m)
{
    int from,to,i;
    for (i = 1; i <= n; ++i) {if (flag[i]==0)
    enQueue(i);}
    while (begin<=tail)
    {
        from = Q[begin];

        for (i = head[from]; i != 0; i = e[i].next)
        {
            to = e[i].b;
            if (--flag[to]==0) {enQueue(to);
            father[to] = from;}
        }
        ++begin;
    }
}

int Compute_path(int start)
{
    int cnt = 1;
    while (father[start]!=0)
    {
        start = father[start];
        ++cnt;
    }
    return cnt;
}


int main()
{
    int n,m,i,from,to,maxi = 0;
    cin >> n >> m;
    for(i = 1; i <= m; ++i)
    {
        cin >> from;
        cin >> to;
        e[i].a = from;
        e[i].b = to;
        e[i].next = head[from];
        ++flag[to];
        head[from] = i;
    }
    topsort(n,m);
    for (i = 1; i <= n; ++i)
    {
        if (Compute_path(i)>maxi) maxi = Compute_path(i);
    }
    cout << maxi << endl;
    return 0;
}
