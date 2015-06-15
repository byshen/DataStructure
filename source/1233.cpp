#include <iostream>

using namespace std;

struct {
int a,  b;
int next;
} e[101];

int head[101] = {0}, mark[101] = {0},M,cnt = 0;

void DFS(int dep, int start)
{
    int i,to;
    mark[start] = 1;
    if (dep==M) {++cnt; mark[start] = 0;return;}
    for (i = head[start]; i!=0; i= e[i].next)
    {
        to = e[i].b;

        if (!mark[to])
           {
               mark[to] = 1;
               DFS(dep+1,to);
               mark[to] = 0;
           }
    }
    mark[start] = 0;
}

int main()
{
    int n , m, start;
    int i, to ,from;
    cin >> n >> m >> start >> M;
    for (i = 1; i <= m; ++i)
    {
        cin >> from >> to;
        e[i].a = from;
        e[i].b = to;
        e[i].next = head[from];
        head[from] = i;
    }
    DFS(0,start);
    cout << cnt;
    return 0;
}


