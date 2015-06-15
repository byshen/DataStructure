#include <iostream>

using namespace std;

int a[1000000];

void swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void qsort(int s, int t)
{
    if (s >= t) return;
    int i = s, j = t, mid = a[(s+t)>>1];
    while (i <= j)
    {
        while (a[i]<mid) ++i;
        while (a[j]>mid) --j;
        if (i <= j)
        {
            swap(a[i++],a[j--]);
        }
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
    for (i = 1; i <= N; ++i)
    cout << a[i] << ' ';

    return 0;
}
