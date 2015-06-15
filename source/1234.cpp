#include <iostream>

using namespace std;

int parent[100001],a[100001],b[100001],c[100001];

void Union(int root1, int root2)
{
    if (root1==root2) return;
    if (parent[root1]>parent[root2])
    {
        parent[root2] += parent[root1];
        parent[root1] = root2;
    }
    else
    {
        parent[root1] += parent[root2];
        parent[root2] = root1;
    }
}

int Find(int x)
{
    if (parent[x]<0) return x;
    else return parent[x] = Find(parent[x]);
}

void swap(int &x, int &y)
{
     int tmp = x;
     x = y;
     y = tmp;
}

void qsort(int s, int t, int a[], int b[], int c[])
{
    if (s >= t) return ;
    int i = s, j = t, mid = a[(s+t)>>1];
    while (i <= j)
    {
        while (a[i]<mid) ++i;
        while (a[j]>mid) --j;
        if (i <= j)
        {
            swap(a[i],a[j]);swap(b[i],b[j]);swap(c[i],c[j]);
            ++i;
            --j;
        }
    }
    qsort(s,j,a,b,c);
    qsort(i,t,a,b,c);
}

int main()
{
    int i,n,m,u,v,result = 0,current_edge = 0;
    cin >> n >> m;
    for (i = 1; i <= m; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    qsort(1,m,c,a,b);
    for (i = 1; i <= n; ++i)
    parent[i] = -1;
    i = 1;
    while (current_edge<n-1)
    {
        u = Find(a[i]);
        v = Find(b[i]);
        if (u == v) ++i;
        else {
        Union(u,v);
        result += c[i];
        ++i;
        ++current_edge;
        }
    }
    cout << result << endl;
}
