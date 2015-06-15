#include <iostream>

using namespace std;

int cnt = 1, a[2000001];

void swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void qsort(int s, int t)
{
    if (s >= t) return;
    int i = s, j = t, mid = a[(s+j)>>1];
    while (i <= j)
    {
        while (a[i]<mid) ++i;
        while (a[j]>mid) --j;
        if (i <= j)
        swap(a[i++],a[j--]);
    }
    qsort(s,j);
    qsort(i,t);
}

int main()
{
    int N,i;
    cin >> N;
    for (i = 1; i <= N; ++i)
        cin >> a[i];
    qsort(1,N);
    for  (i = 2; i <= N; ++i)
    {
        if (a[i]!=a[i-1]) ++cnt;
    }
    cout << cnt;
}
