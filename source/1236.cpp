#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("1.txt");

int Q[200001], dist[200001],head[200001],mark[200001],father[200001],begin = 1,tail = 0;

struct {
int a, b;
int next;
int value;} e[200001];

bool enQueue(int i)
{
    if (mark[i]) return false;
    mark[i] = 1;
    ++tail;
    Q[tail] = i;
    return true;
}

void SPFA()
{
    int from, to,i;
    while (begin <= tail)
    {
        from = Q[begin];
        ++begin;
        for (i = head[from]; i!=0; i = e[i].next)
        {
            to = e[i].b;
            if (dist[to]>dist[from]+e[i].value)
            {
                dist[to] = dist[from]+e[i].value;
                enQueue(to);
                father[to] = from;
            }
        }
        mark[from] = 0;
    }
}

int result[10001];

int main()
{
    int i,n,m,start,end,from,to,v,cnt = 0;
    cin >> n >> m >> start >> end;
    for (i = 1; i <= m; ++i)
    {
        cin >> from >> to >> v;
        e[i].a = from;
        e[i].b = to;
        e[i].value = v;
        e[i].next = head[from];
        head[from] = i;
    }
    for (i = 1; i <= n; ++i)
    {
        dist[i] = 99999999;
    }
    dist[start] = 0;
    enQueue(start);
    SPFA();
    cout << dist[end] << endl;
    while (end!=0)
    {
        result[cnt] = end;
        ++cnt;
        end = father[end];
    }
    for (i = cnt-1; i >= 0; --i)
    {
        cout << result[i] << ' ';
    }
    return 0;
}
